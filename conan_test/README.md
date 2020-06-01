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

## Source

This is a CMake skeleton with unit tests.

[Source](https://github.com/alvarogarcia7/c-simple-sessions/tree/master/skeleton_cmake)
