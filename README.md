## FreeRTOS+POSIX: Portable Operating System Interface (POSIX threading wrapper) for FreeRTOS

The Portable Operating System Interface (POSIX) is a family of standards specified by the IEEE Computer Society for maintaining compatibility between operating systems. FreeRTOS+POSIX implements a subset of the [POSIX threading](https://pubs.opengroup.org/onlinepubs/7908799/xsh/threads.html) API.

With FreeRTOS+POSIX, an existing POSIX threading compliant application can be ported to run on the FreeRTOS kernel, and therefor leverage all the [Amazon FreeRTOS](https://www.freertos.org/FAQ_Amazon.html) functionality. Additionally, a library designed for use with POSIX threading compatible operating systems can be ported to FreeRTOS kernel based applications.

For more on FreeRTOS+POSIX, please visit [freertos.org](https://www.freertos.org/FreeRTOS-Plus/FreeRTOS_Plus_POSIX/index.html)

The demo project is located under ```FreeRTOS-Plus\Demo\FreeRTOS_Plus_POSIX_with_actor_Windows_Simulator```. 

## Cloning
This repo uses [Git Submodules](https://git-scm.com/book/en/v2/Git-Tools-Submodules) to bring in dependent components.

Note: If you download the ZIP file provided by GitHub UI, you will not get the contents of the submodules. (The ZIP file is also not a valid git repository)

To clone using HTTPS:
```
git clone https://github.com/FreeRTOS/Lab-Project-FreeRTOS-POSIX.git --recurse-submodules
```
Using SSH:
```
git clone git@github.com:FreeRTOS/Lab-Project-FreeRTOS-POSIX.git --recurse-submodules
```

If you have downloaded the repo without using the `--recurse-submodules` argument, you need to run:
```
git submodule update --init --recursive
```