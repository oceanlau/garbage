# Computer Networks

My summary notes from Avi and Gabe's JHU CS 414/614 Computer Networks course 2020 spring.

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

### 802.15 (Bluetooth)

-   Infrastructure: Ad-hoc net. Master/slaves/parked(inactive) devices within a local net.

### Cellular Net

-   Infrastructure: Cell (Base station + mobile users), mobile switching center, etc.
-   Combined FDMA/TDMA/CDMA to support more users
-   2G (Voice), 3G (Voice + data), 4G (All IP)

### Handling Mobility

-   How:
    -   Do nothing and let routing handle it: not scalable, too many losses.
    -   Indirect routing (often used): Inform home agent about host's new address when host move to another network and let the home agent and foreign agent forward data to it. Longer delay.
    -   Direct routing: Correspondent agent get the new address of a host from home agent and directly connect to it. Shorter delay but 'unfair' (too much work) to the correspondent agent.
-   Mobile IP: Implements indirect routing above.
-   Cellular net (GSM): Also indirect routing. Roaming address is acquired by querying the cellular net provider.
    -   Handoff: Base stations, host and cellular net provider coordinate to serve a moving host.