// Fill out your copyright notice in the Description page of Project Settings.


#include "JsonParser/SocobanParser.h"

#include "JsonParser/MapModel.h"
#include "JsonParser/MapTileStruct.h"

UMapModel* USocobanParser::ParseMap(FString FileLocalPath)
{
	bool bOk = true;

	UMapModel* MapModel = NewObject<UMapModel>(UMapModel::StaticClass());

	FString FullPathContent = FPaths::ProjectContentDir() + "Maps/" + FileLocalPath;


	FString jsonStr;
	if(!FPlatformFileManager::Get().GetPlatformFile().FileExists(*FullPathContent))
	{
		bOk = false;
	}

	if(bOk)
	{
		FFileHelper::LoadFileToString(jsonStr, *FullPathContent);


		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(jsonStr);
		TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
		FJsonSerializer::Deserialize(JsonReader, JsonObject);
		


		MapModel->Height = JsonObject->GetIntegerField("height");
		MapModel->Width = JsonObject->GetIntegerField("width");
		TArray<TSharedPtr<FJsonValue>> aTiles = JsonObject->GetArrayField("map");

		for(auto aTile : aTiles)
		{
			FMapTileStruct MapTile;
			MapTile.Tile = (ETileType)aTile->AsObject()->GetIntegerField("tile");
			MapTile.Object = (EObjectType)aTile->AsObject()->GetIntegerField("object");

			MapModel->TilesStructs.Emplace(MapTile);
		}
	}

	return MapModel;

}
