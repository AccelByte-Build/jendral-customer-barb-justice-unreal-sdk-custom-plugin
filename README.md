# AccelByte Customization Unreal SDK

AccelByte Customization Unreal SDK is a custom extension plugin of AccelByte Unreal SDK for Unreal Engine.

## Assumptions

This documentation assumes that you are already familiar with modern C++, Unreal Engine, HTTP, REST API, microservice architecture, OAuth2, OpenID Connect, JWT, WebSocket.

## Dependencies

AccelByte Customization SDK is compatible with these AccelByte Unreal SDK version 6.1.0 and AccelByte Services version 3.2.0 with custom extension

## Features

AccelByte Customization Unreal SDK features:

- Access the API from C++
- Supported Unreal versions: 4.25 - 4.27

## Architecture

The classes are categorized as follow:

- The `Model` classes are used for JSON deserialization and serialization using Unreal Engine [JsonUtilities.h](https://api.unrealengine.com/INT/API/Runtime/JsonUtilities/).
- The `Api` classes provides interface to C++ functions.
- The `Core` classes are for core functionalities (error handler, settings, credential store, and HTTP retry system). 

## Packaging

- `/Plugins` The actual plugin is located in `/Plugins/AccelByteUe4SdkCustomization`.
- `/Source` This contains C++ source code for the examples.
- `/Documentation` This contains Doxyfile and this documentation.
  
## Terminology

> There are only two hard things in Computer Science: cache invalidation and naming things. ―Phil Karlton

# Quickstart Guide

Here's how to get it up and running quickly.

## Setup

1. The first step is to download and install [Visual Studio 2019](https://visualstudio.microsoft.com/downloads/).

2. Download and install [Unreal Engine 4.25](https://www.unrealengine.com).

3. If you want to run the examples, skip to step 7.

4. Create or open existing Unreal Engine project.

5. Setup `AccelByteUe4Sdk` first before custom extension plugin. 

6. Copy the custom extension plugin folder `Plugins/AccelByteUe4SdkCustomization` to your game's plugins folder after AccelByteUe4Sdk setup. 

7. Add the plugins to your `/MyAwesomeGame.uproject` file,
```java
"Plugins": [
...
{
    "Name": "AccelByteUe4Sdk",
    "Enabled": true
},
{
    "Name": "AccelByteUe4SdkCustomization",
    "Enabled": true
},
...
```
in `/Source/MyAwesomeGame.Target.cs`, and in `/Source/MyAwesomeGameEditor.Target.cs`.
```cs
ExtraModuleNames.AddRange(new string[]
{
    ...
    "AccelByteUe4Sdk",
    "AccelByteUe4SdkCustomization",
    ...
}
```
also in `/Source/MyAwesomeGame/MyAwesomeGame.Build.cs`.
```cs
 PublicDependencyModuleNames.AddRange(
			new string[] {
				...
                "AccelByteUe4Sdk",
                "AccelByteUe4SdkCustomization",
                ...
            }
```

# Commit Message Standardization

We are following Conventional Commits as a standard to follow for writing commit messages. The details of the rules can be found in the [conventional commits website](https://www.conventionalcommits.org/en/v1.0.0/). 
