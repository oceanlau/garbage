# Misc

## Google Bigtable

[Bigtable: A Distributed Storage System for Structured Data](https://research.google/pubs/pub27898/)

- Keywords: Distributed, for structured data, multi-dimensional sorted map
- Multi-dimensional sorted map: Key is row name + column name + timestamp. Lexicographic order. Locality benefit: same row data are usually partitioned together or close by. 
- Concurrency: Atomic read or write of a single key. Single-row transaction.
- Infrastructure:
  - GFS
  - SSTable: ordered immutable (append-only) map. Block indexes are loaded into memory so a lookup can be done with a binary search of indexes and a single disk read of the block.
  - Chubby (Using Paxos. 5 replicas. 3 voters make a master): ensure one master server, tablet server discovery, schema store, etc.
- Data is divided into tablets. Each tablet server holds many tablets. Single master manages tablets distribution. Clients directly read from and write to tablet servers.
- Tablet location:
  - Each user table is splitted in to tablets. 
  - A META table stores the location of all these tablets with the row key of table name + end key within the tablet.
  - The META table is also splitted into tablets.
  - A single Chubby file contains the root META table tablet that contains the location of all other META table tablets.
  - Clients caches the whole META table. If it does not know a tablet location, it moves up the tablet location hierarchy to find the result.
- Tablet assignment
- Tablet Serving
  - Each tablet consists of a list of SSTables and memtable.
  - Recovery: Each write first writes to the tablet commit log. Metadata records the list of SSTable files and the redo point of the memtable. During recovery, a tablet server reads this metadata and builds the memtable using the redo point and the commit log.

## Distributed System Theory

- CAP: Consistency (linearizability), availability, partition tolerance
  - RDBMS usually is CA, but in fact can be configured to differently. [https://stackoverflow.com/a/36538087](https://stackoverflow.com/a/36538087).
  - Master-slave storages are usually considered to be CP, like Google Spanner, Apache HBase, MongoDB. Redis can also be considered CP becaues slaves without master are not working. [https://blog.nahurst.com/visual-guide-to-nosql-systems](https://blog.nahurst.com/visual-guide-to-nosql-systems).
  - Multi-leader or leaderless storages are usually considered to be AP, like Amazon DynamoDB, Apache Cassandra.
- Linearizability usage: lock, leader election, uniqueness
- Type of linearizability: Total order, causality (loose)
- Implementation:
  - Two-phase commit: Blocking, must in sync. Coordinator, single point of faulure.
  - Consensus algorithm: quorums, nonblocking. Re-election, fault-tolerant.

## Redis

- Mostly single threaded ([https://redis.io/topics/benchmarks](https://redis.io/topics/benchmarks)). In-memory. I/O multiplexing (event-driven).
- Data Types: [https://redis.io/topics/data-types-intro](https://redis.io/topics/data-types-intro)

## ZooKeeper

- It is essentially a service for distributed systems offering a hierarchical key-value store, which is used to provide a distributed configuration service, synchronization service, and naming registry for large distributed systems.
- Implements CP of CAP.

## MongoDB

- A schema-less document data base with deep query-ability that is nearly as powerful as SQL.

## Message Queue

- Async, avoid peak traffic, decouple

## System Design Interview Prep

- API Rate Limiting
  - Easy if we limit on each host. But because each host consumes requests at different rate, we may need to throttle taking into account all the hosts. Now we are facing a distributed system problem.
  - Token bucket algorithm. If implemented in the host, hosts need to communicate token consumption with each other.

## More Concepts

- Row store, wide-column store, columnar store
  - Row store: RDBMS
  - Wide-column store: Google Bigtable
  - Columnar store:
- Normalization and Denormalization
  - Normalization: reduce redundancy in accordance to the normal forms.
  - Denormalization: usually means storing redundant information (table) for higher read performance.

## Computer Network Theory

- Application Level
  - Socket: Endpoint (door) for application process sending and receiving data through network.
  - HTTP

- Transport Level
  - TCP: handshake (SYN, SYN+ACK, ACK), handwave (FIN, ACK -> FIN, ACK). Handwave has one more message than handshake because there may be more data left to send.

- Network Layer

- Link Layer

## Web Security

- XSS: Inject script into the site and let victims runs. Reflected XSS is often hand-crafted url and Stored XSS is often injected HTML (maybe by posting comments) on the site. Usually prevented by escaping HTML entity.
- CSRF: Send request on behalf of victims when visiting malicious site. Can be prevented by one-time token or use JavaScript to read token from cookie.