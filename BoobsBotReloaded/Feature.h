#pragma once
#include <functional>
#include <vector>

namespace Feature
{
	enum FeatureType
	{
		Ui,
		Frame,
		None
	};

	class Feature
	{
	public:
		int Id;
		FeatureType Type;
		char* Name;
		char* Description;
		bool Enabled;

		Feature(char* name,FeatureType type,char* description,bool enabled,std::function<void(bool)> feature_function)
		{
			Id = -1;
			Name = name;
			Type = type;
			Description = description;
			Enabled = enabled;
			Function = feature_function;
		}

		void Toogle();
		void Execute();
	private:
		std::function<void(bool)> Function;
	};

	namespace Manager
	{
		static std::vector<Feature> Features;

		void AddNewFeature(Feature feature_to_add);
		void ExecuteUiFeatures();
		void ExecuteFrameFeatures();

		void PrintFeatures();
	}

	void Initialize();
}
