#include "WeatherController.h"
#include "Components/SceneComponent.h"
#include "Kismet/KismetMaterialLibrary.h"
#include "NiagaraFunctionLibrary.h"
#include "Engine/World.h"
#include "Components/ExponentialHeightFogComponent.h"

AWeatherController::AWeatherController()
{
    PrimaryActorTick.bCanEverTick = false;

    // Root component
    Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    RootComponent = Root;

    // Niagara components for rain and snow
    RainSystem = CreateDefaultSubobject<UNiagaraComponent>(TEXT("RainSystem"));
    RainSystem->SetupAttachment(RootComponent);
    RainSystem->bAutoActivate = false;

    SnowSystem = CreateDefaultSubobject<UNiagaraComponent>(TEXT("SnowSystem"));
    SnowSystem->SetupAttachment(RootComponent);
    SnowSystem->bAutoActivate = false;
}

void AWeatherController::BeginPlay()
{
    Super::BeginPlay();

    // Deactivate both systems on start
    if (RainSystem) RainSystem->Deactivate();
    if (SnowSystem) SnowSystem->Deactivate();
}

void AWeatherController::SetWeather(FString WeatherType)
{
    UE_LOG(LogTemp, Warning, TEXT("Setting Weather to: %s"), *WeatherType);

    if (WeatherType == "Rain")
    {
        if (RainSystem) RainSystem->Activate();
        if (SnowSystem) SnowSystem->Deactivate();

        if (WetnessParam)
        {
            UKismetMaterialLibrary::SetScalarParameterValue(this, WetnessParam, "Wetness", 1.0f);
        }

        if (Fog && Fog->GetComponent())
        {
            Fog->GetComponent()->SetFogDensity(0.2f);
        }
    }
    else if (WeatherType == "Snow")
    {
        if (SnowSystem) SnowSystem->Activate();
        if (RainSystem) RainSystem->Deactivate();

        if (WetnessParam)
        {
            UKismetMaterialLibrary::SetScalarParameterValue(this, WetnessParam, "Wetness", 0.5f);
        }

        if (Fog && Fog->GetComponent())
        {
            Fog->GetComponent()->SetFogDensity(0.3f);
        }
    }
    else // Clear or default
    {
        if (RainSystem) RainSystem->Deactivate();
        if (SnowSystem) SnowSystem->Deactivate();

        if (WetnessParam)
        {
            UKismetMaterialLibrary::SetScalarParameterValue(this, WetnessParam, "Wetness", 0.0f);
        }

        if (Fog && Fog->GetComponent())
        {
            Fog->GetComponent()->SetFogDensity(0.0f);
        }
    }
}
