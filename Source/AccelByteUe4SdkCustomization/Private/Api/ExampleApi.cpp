#include "Api/ExampleApi.h"

namespace AccelByte
{
	namespace Api
	{
		ExampleApi::ExampleApi(Credentials const& CredentialsRef, Settings const& SettingsRef, FHttpRetryScheduler& HttpRef) :
			FApiBase(CredentialsRef, SettingsRef, HttpRef)
		{}
		
		ExampleApi::~ExampleApi() {}
	}
}