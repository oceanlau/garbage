# Computer Networks

## Wireless

### Basics

-   Infrastructure: Base station (access to the wired net for clients) or ad-hoc net (among clients)
-   Standards:
    -   Short range: 802.15 (Bluetooth), 802.11 (WiFi)
    -   Long range: 2G - 5G
-   Wireless characteristics compared to wired: All kinds of interference and hidden terminal problem (hard to sense if the medium is busy) caused by obstacle between senders and signal fading
-   CDMA (Code Division Multiple Access): Recovers original data from one of the senders using its assigned code by Linear Algebra magic.

### 802.11 (WiFi)

-   Infrastructure: Base station (aka Access Point). Take 802.11 b/g for example, there are 11 channels (only 1, 6, 11 channel has no overlap with each other). AP admin must assign one channel number to an AP. Each host must associate with one AP.
-   CSMA/CA: No collision detection compared to wired version (CSMA/CD).
    -   Because the stength of received signal is usually small compared to transmitted signal, it is costly to build hardware that can detect a collision. CSMA/CA consists of sensing channel availability, random backoff, **wait for a certain time** (Because there is no collision detection, waiting is needed in case others are starting to send at the same time), transmit an entire frame (no collision detection so no abortion), **wait for ACK** (Also because there is no collision detection).
    -   Reserving channel (optional): handling the hidden terminal problem.
-   Frame:
    -   4 MAC addresses: receiver host or AP, sender host or AP, router interface to AP, address in ad-hoc mode. Compared to switch, AP is not transparent (Has MAC address).