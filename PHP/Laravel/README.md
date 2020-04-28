# Learning Laravel: An Outsider's Perspective

Hope this article saves you from all those irritating Laravel jargons when developing for the first time.

## Server Setup

## Install Laravel

### Environmental Variables

There is a `.env` (or `.env.example` if not using Composer to install Laravel) file at the project root. Configuration files like `config/app.php` would look for configuration value in this `.env` file.

To make your modifications work, use `php artisan config:cache` to recache it.

## Developing for Laravel

Like many other web frameworks, Laravel renders a page or API with four main modules: The first one (jargon: **route**) matches the url to a handler module. The handler module (jargon: **controller**) is where you write the core business logic for the page or API. It could call a data module (jargon: **model**) for data from databases or other storages. Finally it sends the processed data to the last module (jargon: **view**) which formats and generates a response. Of course there are many other modules, classes and libraries supporting these four. But we'll focus on these first.

### Develop Web Pages

-   Show your page: First we define the url and the corresponding handler class/method at `routes/web.php`:

    ```PHP
    Route::get('test', 'TestController@index');
    // Laravel also supports adding a function instead of handling class
    // This one returns a view module without any logic.
    Route::get('/', function () {
        return view('welcome');
    });
    ```

    Now for our `TestController`:
    ```bash
    # Generate controller file using this command
    php artisan make:controller TestController

    vi app/Http/Controllers/TestController.php
    ```

    ```PHP
    class TestController extends Controller
    {
        //Router TestController@index goes here
        public function index()
        {
            // Simply return a view module
            return view('test');
        }
    }
    ```

    Finally we write our new view module `test`:

    ```bash
    # Create test view file
    vi resources/views/test.blade.php
    ```

    And just put in any valid HTML code.

    ```PHP
    <!DOCTYPE html>
    <html>
    <head>
    <meta charset="UTF-8">
    <title>Hello</title>
    </head>
    <body>
    Testing.
    </body>
    </html>
    ```

    You can run the Laravel built-in server locally using command `php artisan serve`. If you are developing on your local machine with a browser, you can go to `http://127.0.0.1:8000/test` and see your page. Otherwise using command `curl http://127.0.0.1:8000/test` to see your server output.

-   Insert your data: First we create our database table and a corresponding data module (model) to manipulate the table. Then we call this model from controller to insert data. The model of Laravel provides us with a lot of conveient APIs to manipulate data tables without writing SQL.

    1. To post data to a url, simply add this to `routes/web.php`:

    ```PHP
    Route::post('note', 'NoteController@store');
    ```

    2. Create our controller:

    ```bash
    # Generate controller file using this command
    php artisan make:controller NoteController

    vi app/Http/Controllers/NoteController.php
    ```

    ```PHP
    public function store(Request $request) {
        // We are using model Note.
        // This create API is provided by Laravel.
        $note = Note::create([
            'title' => $request->title,
            'author' => $request->author,
            'content' => $request->content,
        ]);

        // Assume the request is ajax, we respond with a JSON.
        return response()->json([
            'status' => 0,
            'msg' => '',
            'data' => $note
        ], 201);
        
        // If it is a form submit, we can also redirect user to a page.
        // Below we direct the user back to where he/she came from.
        // return back()->withInput();
    }
    ```

    3. Create our table and model. Laravel provide scripts (jargon:**migration**) to create tables for us.

    ```bash
    # -m tells Laravel to create model for us at the same time
    php artisan make:migration Note -m

    vi database/migrations/DATETIME_create_notes_table.php
    ```

    ```PHP
    public function up()
    {
        Schema::create('notes', function (Blueprint $table) {
            $table->bigIncrements('id');
            $table->string('title', 100)->default('');
            $table->string('author', 100)->default('');
            $table->string('content', 800)->default('');
            $table->timestamps();
        });
    }

    public function down()
    {
        Schema::dropIfExists('notes');
    }
    ```

    ```bash
    # Run your scripts (all of them) to create the table
    php artisan migrate

    # Now edit our model file
    vi app/Note.php
    ```

    ```PHP
    // Add the column names that were used in Note::create at our controller
    // Otherwise Laravel won't let us insert like that
    protected $fillable = ['title', 'author', 'content'];
    ```

    Now if we post something to our url, you can see the result.

    ```bash
    ```

-   Retrieve your data: Similarly, we edit our route and controller file:

    ```PHP
    // routes/web.php
    // In case your url path is long, we can give it a name like this.
    // So we can easily get this url string anywhere in our app.
    Route::get('note', 'NoteController@showNotes')->name('note');
    ```

    ```PHP
    // app/Http/Controllers/NoteController.php
    ```

-   Update your data: The only difference from create and retrieve process is the model API we use in our controller:

    ```PHP
    ```

-   Front end: It's going to take a long time introducing the modern front end technology stack. If not interested, you can use old-fashion HTML/CSS/JS in Laravel like this:

    ```PHP
    ```

    If you do have the patience to learn, Laravel has the most popular front end frameworks (Bootstrap, Vue, React) and module bundler (Webpack) builtin for us. So you can easily reap the benefit:

    ```bash
    # Install the front end package prepared by Laravel
    # This command sometimes takes up to a few minuts
    composer require laravel/ui --dev

    # Generate basic scaffolding. Choose one.
    php artisan ui bootstrap
    php artisan ui vue
    php artisan ui react

    # Install the scaffolding
    npm install
    ```

    Every time you modifies JS or SASS, run `npm run dev` to generate final JS and SASS assets.

-   Pagination:

-   Handling user: Usually if you are letting user posting content on your site, you need to implement register, login, verification, password reset, session and logout the whole package. How to implement all of these is beyond the scope of this article. Luckily Laravel has these all built-in for us. Using the command below will generate all the code, including route, view, controller and model, for us:

    ```bash
     # If you haven't already
    composer require laravel/ui --dev

    # Generate login / registration scaffolding. Choose one.
    php artisan ui bootstrap --auth
    php artisan ui vue --auth
    php artisan ui react --auth

    # Install the scaffolding
    npm install
    # Generate final assets
    npm run dev
    ```

    If you are curious about how they are implemented, you can show all the routes in your app now using command `php artisan route:list`. (They hid them behind a `Auth::routes();` function call so you won't see them at `routes/web.php`). Their controller code are at [https://github.com/laravel/framework/blob/6.x/src/Illuminate/Foundation/Auth/AuthenticatesUsers.php](https://github.com/laravel/framework/blob/6.x/src/Illuminate/Foundation/Auth/AuthenticatesUsers.php)

    You can control where your app jumps to after login at `app/Http/Providers/RouteServiceProvider.php` `public const HOME = '/home';`.

### Develop APIs

-   Request validation: create a request class and put our validation code there:

    ```bash
    # Create a request class
    php artisan make:request StoreNote

    vi app/Http/Requests/StoreNote.php
    ```

    ```PHP
    // Authorization check code here. You can access $this->user(), $this->{PARAMETER_NAME},
    // $this->route, your model class, etc. to check user privilege.
    public function authorize()
    {
        return $this->user()->name == $this->author;
    }

    // Request parameter check rules here.
    // Validation rules provided by Laravel should be enough: https://laravel.com/docs/master/validation#available-validation-rules
    public function rules()
    {
        return [
            'title' => 'required|max:100',
            'author' => 'required|max:100',
            'content' => 'required|max:800',
        ]
    }

    // Customize validation error messages here.
    public function messages()
    {
        return [
            'content.required' => 'Content is required!',
        ]
    }
    ```

    Finally, put it to work by replacing the request class in your controller `app/Http/Controllers/NoteController.php`:

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

-   Force JSON response: Laravel has prewritten some API code for us, but did not enforce a JSON reponse. Since nowadays it would be strange to most clients that an API returns a HTML page instead of a JSON object, for most of us we'd better enforce JSON reponses on API calls ourselves.

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
            } else if ($exception instanceof \Illuminate\Auth\Access\AuthorizationException
                || $exception instanceof \Illuminate\Auth\AuthenticationException) {
                $msg = $exception->getMessage();
                $http_code = 403;
            } else if ($exception instanceof \PDOException) {
                $msg = 'Database error';
            } else if ($exception instanceof \Illuminate\Database\Eloquent\ModelNotFoundException) {
                $msg = 'Resource not found';
                $http_code = 404;
            }

            return response()->json([
                'status' => $status,
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
    # Run your scripts (all of them)
    php artisan migrate
    # If you regret your last modification
    php artisan migrate:rollback --step=1
    ```