# MED Task Server

## Description :
This simple CLI application is designed to read data from excel file and emit it via networking port to multiple clients using threads.

## Dependencies

* QT 4.8
* [XLNT](https://github.com/tfussell/xlnt) library for manipulation of excel v1.2
* CMake v3.2

## Followed procedure:
1. Upon launching, the server checks for an excel file. If not found, it's randomly generated with 10K records.
2. A TCP server is started listening on `1234` port number and starts the eternal waiting.
3. Upon client connection, a thread is spawned to deal with the client, and the main thread returns to the waiting state.
4. In the thread, the client is expected to send the starting row inside excel file. Upon receiving the thread keeps sending the data till the EOF.

