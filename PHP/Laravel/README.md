# Learning Laravel: An Outsider's Perspective

Hope this article saves you from all those irritating Laravel jargons when developing for the first time.

## Server Setup

## Install Laravel

### Environmental Variables

There is a `.env` (or `.env.example` if not using Composer to install Laravel) file at the project root. Configuration files like `config/app.php` would look for configuration value in this `.env` file.

To make your modifications work, use `php artisan config:cache` to recache it.

## Developing for Laravel

### Develop Web Pages

### Develop APIs

-   Request Validation: create a request class and put our validation code in there:

    ```bash
    # Create a request class
    php artisan make:request StoreNote

    vi app/Http/Requests/StoreNote.php
    ```

    ```PHP
    # Authorization code here. You can access $this->user(), $this->{PARAMETER_NAME}, $this->route, your model class, etc. to check user privilege. Return false causes a 4xx HTTP error.# todo
    public function authorize()
    {
        return $this->user()->name == $this->author;
    }

    # Request parameter check rules here. Validation rules provided by Laravel should be enough: https://laravel.com/docs/master/validation#available-validation-rules
    public function rules()
    {
        return [
            'title' => 'required|max:100',
            'author' => 'required|max:100',
            'content' => 'required|max:800',
        ]
    }

    # Customize validation error messages here.
    public function messages()
    {
        return [
            'content.required' => 'Content is required!',
        ]
    }
    ```

    Finally, put it to work by replace the request class in your controller `app/Http/Controllers/NoteController.php`:

    ```PHP
    <?php
    // ...
    use App\Http\Requests\StoreNote; // Add this line

    class NoteController extends Controller
    {
        public function store(StoreNote $request) { // Change the class name
        // ...
        }
    // ...
    }
    ```

-   Force JSON: Laravel has prewritten some API code for us, but did not enforce a JSON reponse. Since nowadays it would be strange to most clients that an API returns a HTML page instead of a JSON object, for most of us we'd better enforce JSON reponses on API calls ourselves.

    Obviously it would be a bad idea to force Laravel to return JSON on every kind of request. Surely We can return JSON from our controller code. But when there is an exception, including validation failure and authentication failure, the default way of Laravel handling it is still returning HTML.

    That's why the healthy way would be distinguishing requests from API calls and webpage calls, and only enforcing JSON response on API calls. This method below is borrowed from [@DarkGhostHunter at medium](https://medium.com/@DarkGhostHunter/laravel-convert-to-json-all-responses-automatically-c4a72b2fd3ac) and others:

    1. Define a function (jargon: **middleware**) that sets all incoming HTTP request header 'Accept' to 'application/json'. We later use this to distinguish API calls.

    ```bash
    # Create a middleware file
    php artisan make:middleware RequestJson

    vi app/Http/Middleware/RequestJson.php
    ```

    ```PHP
    // Modify the code
    class RequestJsonMiddleware
    {
        public function handle($request, Closure $next)
        {
            $request->headers->set('Accept', 'application/json'); // Add this line
            return $next($request);
        }
    }
    ```

    2. Register this middleware to Laravel by modifying `app/Http/Kernel.php` file:

    ```PHP
    // Register it and give it a name
    protected $routeMiddleware = [
         'auth' => \App\Http\Middleware\Authenticate::class,
         'auth.basic' => \Illuminate\Auth\Middleware\AuthenticateWithBasicAuth::class,
         // ...
         'throttle' => \Illuminate\Routing\Middleware\ThrottleRequests::class,
         'verified' => \Illuminate\Auth\Middleware\EnsureEmailIsVerified::class,

         'request_json' => \App\Http\Middleware\RequestJson::class, // Add this line
     ];

    // Because we should set header before any other process, we give it the highest priority
    protected $middlewarePriority = [
        \App\Http\Middleware\RequestJson::class, // Add this line here
        \Illuminate\Session\Middleware\StartSession::class,
        // ...
        \Illuminate\Auth\Middleware\Authorize::class,
    ];
    ```

    3. Put it to work. Add `request_json` middleware to `routes/api.php` file:

    ```PHP
    Route::group(['middleware' => ['request_json', 'auth:api']], function(){
         Route::post('note', 'NoteController@store');
     });
    ```

    4. Modify all the exception handling code in one place `app/Exceptions/Handler.php`:

    ```PHP
    public function render($request, Exception $exception)
    {
        // Add this part of code
        if ($request->wantsJson()) { // This checks if the request has the specified header
            $status = 1;
            $msg = 'Unknown error';
            $http_code = 500;

            if ($exception instanceof \Illuminate\Validation\ValidationException) {
                $msg = $exception->getMessage();
                $http_code = 422;
            } else if ($exception instanceof \Illuminate\Auth\Access\AuthorizationException || $exception instanceof \Illuminate\Auth\AuthenticationException) {
                $msg = $exception->getMessage();
                $http_code = 403;
            } else if ($exception instanceof \PDOException) {
                $msg = 'Database error';
            } else if ($exception instanceof \Illuminate\Database\Eloquent\ModelNotFoundException) {
                $msg = 'Resource not found';
                $http_code = 404;
            }

            return response()->json([
                'stats' => $status,
                'msg' => $msg,
                'data' => []
            ], $http_code);
        }

        return parent::render($request, $exception);
    }
    ```

### Log

-   Laravel supports eight logging levels defined in the RFC 5424 specification: emergency, alert, critical, error, warning, notice, info and debug:

    ```PHP
    use Illuminate\Support\Facades\Log;

    // eg. log an exception
    $err_class = get_class($exception);
    Log::error("err_class[\\{$err_class}] err_code[{$exception->getCode()}] err_msg[{$exception->getMessage()}]", [ 'key'=>'value' ]);
    ```

### Query your database

-   Create your tables in database

    Laravel provides us with a fancy command to generate a PHP script that create or modify table schemas for you. The idea behind this is to keep track of all the database modifications in a series of PHP files. So it is kind of like version control of your database schemas:

    ```bash
    # In your project root folder:
    php artisan make:migration DB_OPERATION_SCRIPT_NAME # this is part of the name of the generated script
    # Then add your modification code here
    vi database/migrations/DATETIME_DB_OPERATION_SCRIPT_NAME.php
    ```

    This script grammar is listed here: [https://laravel.com/docs/master/migrations](https://laravel.com/docs/master/migrations). Remember it is best to implement the `down` method in case you need to rollback your modification in the future.

    ```bash
    # Run your script (all of it)
    php artisan migrate
    # If you regret your last modification
    php artisan migrate:rollback --step=1
    ```


