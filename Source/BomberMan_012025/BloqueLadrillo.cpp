#include "BloqueLadrillo.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

ABloqueLadrillo::ABloqueLadrillo()
{
	// asignar el material original
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialOriginalFinder(TEXT("Material'/Game/StarterContent/Materials/M_Brick_Clay_New.M_Brick_Clay_New'"));
    if (MaterialOriginalFinder.Succeeded())
    {
        MaterialOriginal = MaterialOriginalFinder.Object;
	}

	//  asignar el material dañado
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialDaniadoFinder(TEXT("Material'/Game/StarterContent/Materials/M_Brick_Cut_Stone.M_Brick_Cut_Stone'"));
    if (MaterialDaniadoFinder.Succeeded())
    {
        MaterialDaniado = MaterialDaniadoFinder.Object;
	}

    TiempoDestruccion = 2.0f;

    // Guardar el material original si está disponible
    if (Malla)
    {
        MaterialOriginal = Malla->GetMaterial(0);
    }

	// asignar el sonido de rompimiento
    static ConstructorHelpers::FObjectFinder<USoundBase> SonidoRompimientoFinder(TEXT("SoundCue'/Game/BomberMan_012025/Audio/SonidoRompimiento_Cue.SonidoRompimiento_Cue'"));
    if (SonidoRompimientoFinder.Succeeded())
    {
        SonidoRompimiento = SonidoRompimientoFinder.Object;
	}

}

void ABloqueLadrillo::BeginPlay()
{
    Super::BeginPlay();
    
    // Prueba de comportamiento individual y grupal
    //ComportamientoIndividual();
    ComportamientoGrupo();
}

void ABloqueLadrillo::ComportamientoIndividual()
{
    UE_LOG(LogTemp, Warning, TEXT("BloqueLadrillo: ¡Impacto individual! Se destruye."));

    if (SonidoRompimiento)
    {
        UGameplayStatics::PlaySoundAtLocation(this, SonidoRompimiento, GetActorLocation());
    }

    Destroy(); // Se destruye al primer impacto
}

void ABloqueLadrillo::ComportamientoGrupo()
{
    UE_LOG(LogTemp, Warning, TEXT("BloqueLadrillo: ¡Colapso en grupo! Destrucción en cadena activada."));

    // Cambiar a un material que denote daño visual
    if (MaterialDaniado && Malla)
    {
        Malla->SetMaterial(0, MaterialDaniado);
    }

    // Activar destrucción con retardo (simula colapso)
    GetWorldTimerManager().SetTimer(
        TimerHandleDestruir,
        this,
        &ABloqueLadrillo::DestruirBloque,
        TiempoDestruccion,
        false
    );
}

void ABloqueLadrillo::DestruirBloque()
{
    if (SonidoRompimiento)
    {
        UGameplayStatics::PlaySoundAtLocation(this, SonidoRompimiento, GetActorLocation());
    }

    UE_LOG(LogTemp, Warning, TEXT("BloqueLadrillo: ¡Destruido tras colapso grupal!"));
    Destroy();
}