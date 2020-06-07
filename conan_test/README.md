# Conan + CMake

Goal:

  * Manage the dependencies using [Conan Package Manager](https://conan.io/)
  * Remove uncertainty when using this setup for a professional project
  
## Pre-requisites

  * `conan`
  * `gcc` (a modern version)
  * `cmake` (a modern version)
  
There is a setup in the Makefile that satisfies all these dependencies.

## Scope

### In and out of the container

If you are using it inside a docker container, you might need to execute the program through the container itself. 

The reason is `cmake` (on the host) cannot find the folder with the dependencies.

## Using it

First time:

```bash
cd conan_test
make init 
make install-dependencies 
make build
make execute
```

Following times:

```bash
make install-dependencies # Only when changing dependencies
make build 
make execute
```

(Note: `make` goals can be concatenated)

### Successful execution

This sample program queries the stargazers of Conan, using a GitHub's ReST API

A sample execution:

```json
[
  {
    "login": "kotarac",
    "id": 1216749,
    "node_id": "MDQ6VXNlcjEyMTY3NDk=",
    "avatar_url": "https://avatars3.githubusercontent.com/u/1216749?v=4",
    "gravatar_id": "",
    "url": "https://api.github.com/users/kotarac",
    "html_url": "https://github.com/kotarac",
    "followers_url": "https://api.github.com/users/kotarac/followers",
    "following_url": "https://api.github.com/users/kotarac/following{/other_user}",
    "gists_url": "https://api.github.com/users/kotarac/gists{/gist_id}",
    "starred_url": "https://api.github.com/users/kotarac/starred{/owner}{/repo}",
    "subscriptions_url": "https://api.github.com/users/kotarac/subscriptions",
    "organizations_url": "https://api.github.com/users/kotarac/orgs",
    "repos_url": "https://api.github.com/users/kotarac/repos",
    "events_url": "https://api.github.com/users/kotarac/events{/privacy}",
    "received_events_url": "https://api.github.com/users/kotarac/received_events",
    "type": "User",
    "site_admin": false
  },
...
]
```

This has been tested on 2020-06-01, using:

```bash
➜  conan_test git:(master) ✗ uname -a
Linux pc 5.4.0-31-generic #35-Ubuntu SMP Thu May 7 20:20:34 UTC 2020 x86_64 x86_64 x86_64 GNU/Linux

➜  conan_test git:(master) ✗ cmake --version
cmake version 3.16.3
```


Inside the docker setup:
```bash
make bash # Enter the docker container

conan@4922c2a43073:~$ uname -a
Linux 0a33bafad4a6 5.4.0-31-generic #35-Ubuntu SMP Thu May 7 20:20:34 UTC 2020 x86_64 x86_64 x86_64 GNU/Linux

conan@4922c2a43073:~$ cmake --version
cmake version 3.16.4

conan@4922c2a43073:~$ gcc --version
gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008

conan@4922c2a43073:~$ conan --version
Conan version 1.25.2
```

## Variants

  * To support a libraries explicitly, see commit 558bd84d1d8919e1136f72b4638d003f69b82cb4
  * To support libraries implicitly (transparently), see commit fff079ed62ddfebea832dfec839a87bdf9b4e414

## Links

  * [Conan: getting started](https://docs.conan.io/en/latest/getting_started.html)
  * [Conan: guide to getting started](https://blog.conan.io/2018/06/11/Transparent-CMake-Integration.html)

## Source

This is a CMake skeleton with unit tests.

[Source](https://github.com/alvarogarcia7/c-simple-sessions/tree/master/skeleton_cmake)
