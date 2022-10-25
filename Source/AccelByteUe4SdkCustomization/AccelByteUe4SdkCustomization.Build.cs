// Copyright (c) 2021 AccelByte Inc. All Rights Reserved.
// This is licensed software from AccelByte Inc, for limitations
// and restrictions contact your company contract manager.

using UnrealBuildTool;
using System.IO;
using System;
using System.Collections.Generic;

namespace UnrealBuildTool.Rules
{

public class AccelByteUe4SdkCustomization : ModuleRules
{
    public AccelByteUe4SdkCustomization(ReadOnlyTargetRules Target) : base(Target)
    {
#if UE_4_24_OR_LATER
        bLegacyPublicIncludePaths = false;
        DefaultBuildSettings = BuildSettingsVersion.V2;
#else
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
#endif

        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Public"));
        PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Private"));

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "Sockets",
            "Json",
            "JsonUtilities",
            "Http",
            "WebSockets",
            "Networking",
            "SSL",
            "Icmp",
            "AccelByteUe4Sdk"
        });

        if (Target.bBuildEditor)
        {
            PrivateDependencyModuleNames.AddRange(new string[]
            {
                "Settings"
            });
        }
    }

}
}
