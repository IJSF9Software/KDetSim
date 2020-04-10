#ifndef _KMaterial
#define _KMaterial

//////////////////////////////////////////////////////////////////////////
//                                                                      //
// Material Class                                                       //
//                                                                      //
// Class for material properties                                        //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "TMath.h"
#include "nrutil.h"
#include "TROOT.h"
#include <stdio.h>
#include <stdlib.h>
#include "TArray.h"
#include "TArrayI.h"
#include "TArrayF.h"
#include "TArrayD.h"
#include "TH1.h"
#include "TH2.h"
#include "TF2.h"

#ifdef MSVC
Double_t __declspec(dllexport) KAlpha(Double_t, Double_t, Short_t, Int_t = 0);
Double_t __declspec(dllexport) KM(TH1D *, Float_t, Short_t = 1);
class __declspec(dllexport) KMaterial
#else
Double_t KAlpha(Double_t, Double_t, Short_t, Int_t = 0);
Double_t KM(TH1D *, Float_t, Short_t = 1);
class KMaterial
#endif
{

private:
public:
    static Int_t Mat;              // Material index
    static Float_t Temperature;    // Temperature
    static Int_t Mobility;         // mobility model for each material
    static Int_t ImpactIonization; // impact ionization model

    //////////////////////////////////////////////////////

    KMaterial() { Mat = 1; } // MobMod=1;}
    ~KMaterial(){};
    static Double_t dEdx(Double_t);
    static Float_t dEX(Double_t, Double_t *, Double_t *, Double_t);
    static Float_t Perm(Int_t = 1);
    static Float_t EmeC(Int_t);     // effective electron mass for conductivity
    static Float_t EmhC(Int_t);     // effective hole mass for conductivity

    static Float_t Rho() { return 0; };
    static Int_t MobMod();


    ClassDef(KMaterial, 1)
};
#endif
