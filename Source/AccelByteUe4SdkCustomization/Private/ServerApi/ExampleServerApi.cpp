#include "ServerApi/ExampleServerApi.h"

namespace AccelByte
{
	namespace Api
	{
		ExampleServerApi::ExampleServerApi(ServerCredentials const& CredentialsRef, ServerSettings const& SettingsRef, FHttpRetryScheduler& HttpRef) :
			FServerApiBase(CredentialsRef, SettingsRef, HttpRef)
		{}
		
		ExampleServerApi::~ExampleServerApi() {}
	}
}