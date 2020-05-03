# Parallel Programming

My notes after taking Randal's JHU CS 601.320/420/620 Parallel Programming course.

## MapReduce (Hadoop and GFS)

MapReduce is **a programming model** that is easily parallelized. Google's original implementation runs ontop GFS. The open-source Hadoop! implementation runs on HDFS. Some details worth mentioning:

1. Input/output domain: Map is a transformation. So a Mapper reads text and can output any key and value type. Reduce is a collection. So a Reducer could output different value type but doesn't change the key type.
2. Sorting guarantee: When shuffling, data are route to Reducer based the hash of key to achieve load balancing. So it is not sorted globally. Within one partition at Reducer the keys are sorted.
3. Parallelism cap: For Map, it is up to number of input (usually number of files). For Reduce, it is up to number of keys.
4. Implementation: Master/workers model.
5. System Issues:
    - Master failure: Use checkpoint and restart
    - Failed worker: Heartbeat liveness detection and restart
    - Slow worker: Backup tasks
    - Locality of processing to data: Big deal and they don’t really solve. But much subsequent research does
    - Task granularity: Metadata size and protocol scaling (not inherent parallelism) limit the size of M and R
6. GFS:
    - Google's world-changing distributed file system.
    - Design for failures: Chunks are triple replicated.
    - Out of band: Metadata and data are separated. Master/Chunkservers model.
    - Append-only: Avoid contention to achieve good I/O.