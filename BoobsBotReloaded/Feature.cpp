#include "stdafx.h"
#include "Misc.h"

void Feature::Feature::Toogle()
{
	Enabled = !Enabled;
}

void Feature::Feature::Execute()
{
	Function(Enabled);
}

void Feature::Manager::AddNewFeature(Feature feature_to_add)
{
	feature_to_add.Id = Features.size();
	Features.push_back(feature_to_add);
}

void Feature::Manager::ExecuteUiFeatures()
{
	for (auto feature : Features)
	{
		if (feature.Type == FeatureType::Ui)
			feature.Execute();
	}
}

void Feature::Manager::ExecuteFrameFeatures()
{
	for (auto feature : Features)
	{
		if (feature.Type == FeatureType::Frame)
			feature.Execute();
	}
}

void Feature::Manager::PrintFeatures()
{
	Console::Log("Current features:");
	for (auto element : Features)
	{
		char buffer[1024];
		sprintf_s(buffer, "Id: %i ; Name: %s ; Description: %s ; Enabled: %i", element.Id, element.Name, element.Description, element.Enabled);
		Console::Log(buffer);
	}
}

void Feature::Initialize()
{
	Manager::AddNewFeature(Feature("NoRecoil", FeatureType::None, "Disables the recoil on the gun.", false, Misc::NoRecoil));
}
