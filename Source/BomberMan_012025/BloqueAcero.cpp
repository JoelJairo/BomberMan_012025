#include "BloqueAcero.h"
#include "Kismet/GameplayStatics.h"

ABloqueAcero::ABloqueAcero()
{
	TipoBloque = ETipoBloque::BLOQUE_ACERO;

	// asignar material de acero
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAcero(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Steel.M_Metal_Steel'"));
	if (MaterialAcero.Succeeded())
	{
		Malla->SetMaterial(0, MaterialAcero.Object);
	}

	// asignar sonido de impacto met�lico
	static ConstructorHelpers::FObjectFinder<USoundBase> Sonido(TEXT("SoundCue'/Game/BomberMan_012025/Audio/ImpactoMetal_Cue.ImpactoMetal_Cue'"));

	if (Sonido.Succeeded())
	{
		SonidoImpactoMetalico = Sonido.Object;
	}

	DuracionEstadoGrupo = 5.0f; // segundos de invulnerabilidad

	// Guardar el material original si la malla est� asignada
	if (Malla)
	{
		MaterialOriginal = Malla->GetMaterial(0);
	}

	// Asignar material de grupo (brillante)
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBrillante(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Gold.M_Metal_Gold'"));
	if (MaterialBrillante.Succeeded())
	{
		MaterialGrupo = MaterialBrillante.Object;
	}
}

void ABloqueAcero::BeginPlay()
{
	Super::BeginPlay();

	// Prueba de comportamiento individual y grupal
	/*ComportamientoIndividual();
	ComportamientoGrupo();*/
}

void ABloqueAcero::ComportamientoIndividual()
{
	if (SonidoImpactoMetalico)
	{
		UGameplayStatics::PlaySoundAtLocation(this, SonidoImpactoMetalico, GetActorLocation());
	}

	UE_LOG(LogTemp, Warning, TEXT("BloqueAcero: �Impacto individual detectado!"));
}

void ABloqueAcero::ComportamientoGrupo()
{
	UE_LOG(LogTemp, Warning, TEXT("BloqueAcero: �Formaci�n met�lica activa, es invulnerable temporalmente!"));

	// Cambia el material por uno brillante
	if (MaterialGrupo && Malla)
	{
		Malla->SetMaterial(0, MaterialGrupo);
	}

	// Desactiva colisi�n para simular invulnerabilidad
	SetActorEnableCollision(false);

	// Activa temporizador para restaurar estado original
	GetWorldTimerManager().SetTimer(
		TimerHandleRestaurarEstado,
		this,
		&ABloqueAcero::RestaurarEstadoNormal,
		DuracionEstadoGrupo,
		false
	);
}

void ABloqueAcero::RestaurarEstadoNormal()
{
	UE_LOG(LogTemp, Warning, TEXT("BloqueAcero: Estado grupal terminado. Volviendo a normalidad."));

	// Restaurar material original
	if (MaterialOriginal && Malla)
	{
		Malla->SetMaterial(0, MaterialOriginal);
	}

	// Reactivar colisi�n
	SetActorEnableCollision(true);
}