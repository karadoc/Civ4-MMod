#pragma once

// cityAI.h

#ifndef CIV4_CITY_AI_H
#define CIV4_CITY_AI_H

#include "CvCity.h"

typedef std::vector<std::pair<UnitAITypes, int> > UnitTypeWeightArray;

class CvCityAI : public CvCity
{

public:

	CvCityAI();
	virtual ~CvCityAI();

	void AI_init();
	void AI_uninit();
	void AI_reset();

	void AI_doTurn();

	void AI_assignWorkingPlots();
	void AI_updateAssignWork();

	bool AI_avoidGrowth();
	bool AI_ignoreGrowth();
	int AI_specialistValue(SpecialistTypes eSpecialist, bool bAvoidGrowth, bool bRemove) const;
	int AI_permanentSpecialistValue(SpecialistTypes eSpecialist) const; // K-Mod

	void AI_chooseProduction();

	UnitTypes AI_bestUnit(bool bAsync = false, AdvisorTypes eIgnoreAdvisor = NO_ADVISOR, UnitAITypes* peBestUnitAI = NULL);
	UnitTypes AI_bestUnitAI(UnitAITypes eUnitAI, bool bAsync = false, AdvisorTypes eIgnoreAdvisor = NO_ADVISOR);

	BuildingTypes AI_bestBuilding(int iFocusFlags = 0, int iMaxTurns = 0, bool bAsync = false, AdvisorTypes eIgnoreAdvisor = NO_ADVISOR);
	BuildingTypes AI_bestBuildingThreshold(int iFocusFlags = 0, int iMaxTurns = 0, int iMinThreshold = 0, bool bAsync = false, AdvisorTypes eIgnoreAdvisor = NO_ADVISOR);
	
	/* int AI_buildingValue(BuildingTypes eBuilding, int iFocusFlags = 0) const;
	int AI_buildingValueThreshold(BuildingTypes eBuilding, int iFocusFlags = 0, int iThreshold = 0) const; */
	int AI_buildingValue(BuildingTypes eBuilding, int iFocusFlags = 0, int iThreshold = 0, bool bConstCache = false) const;

	ProjectTypes AI_bestProject();
	int AI_projectValue(ProjectTypes eProject);

	ProcessTypes AI_bestProcess();
	ProcessTypes AI_bestProcess(CommerceTypes eCommerceType);
	int AI_processValue(ProcessTypes eProcess);
	int AI_processValue(ProcessTypes eProcess, CommerceTypes eCommerceType);

	int AI_neededSeaWorkers();

	bool AI_isDefended(int iExtra = 0);
/********************************************************************************/
/* 	BETTER_BTS_AI_MOD							9/19/08		jdog5000		    */
/* 																			    */
/* 	Air AI																	    */
/********************************************************************************/
/* original BTS code
	bool AI_isAirDefended(int iExtra = 0);
*/
	bool AI_isAirDefended(bool bCountLand = false, int iExtra = 0);
/********************************************************************************/
/* 	BETTER_BTS_AI_MOD						END								    */
/********************************************************************************/
	bool AI_isDanger();

	int AI_neededDefenders();
	int AI_neededAirDefenders();
	int AI_minDefenders();
	int AI_neededFloatingDefenders();
	void AI_updateNeededFloatingDefenders();

	int AI_getEmphasizeAvoidGrowthCount() const;
	bool AI_isEmphasizeAvoidGrowth() const;

	int AI_getEmphasizeGreatPeopleCount() const;
	bool AI_isEmphasizeGreatPeople() const;

	bool AI_isAssignWorkDirty() const;
	void AI_setAssignWorkDirty(bool bNewValue);

	bool AI_isChooseProductionDirty() const;
	void AI_setChooseProductionDirty(bool bNewValue);

	CvCity* AI_getRouteToCity() const;
	void AI_updateRouteToCity();

	int AI_getEmphasizeYieldCount(YieldTypes eIndex) const;
	bool AI_isEmphasizeYield(YieldTypes eIndex) const;

	int AI_getEmphasizeCommerceCount(CommerceTypes eIndex) const;
	bool AI_isEmphasizeCommerce(CommerceTypes eIndex) const;

	bool AI_isEmphasize(EmphasizeTypes eIndex) const;
	void AI_setEmphasize(EmphasizeTypes eIndex, bool bNewValue);
	void AI_forceEmphasizeCulture(bool bNewValue);

	int AI_getBestBuildValue(int iIndex);
	int AI_totalBestBuildValue(CvArea* pArea);

	int AI_clearFeatureValue(int iIndex);
	// K-Mod note: the following functions were originally created by jdog5000 for debugging BBAI. I've adopted them and changed them.
	int AI_getGoodTileCount() const;
	int AI_countWorkedPoorTiles() const;
	int AI_getTargetPopulation() const;
	int AI_getImprovementValue(CvPlot* pPlot, ImprovementTypes eImprovement, int iFoodPriority, int iProductionPriority, int iCommercePriority, int iFoodChange, int iClearFeatureValue = 0, bool bEmphasizeIrrigation = false, BuildTypes* peBestBuild = 0) const;
	void AI_getYieldMultipliers(int &iFoodMultiplier, int &iProductionMultiplier, int &iCommerceMultiplier, int &iDesiredFoodChange) const;
	// K-Mod end
	BuildTypes AI_getBestBuild(int iIndex) const;
	int AI_countBestBuilds(CvArea* pArea) const;
	void AI_updateBestBuild();

	virtual int AI_cityValue() const;

	int AI_calculateWaterWorldPercent();

	int AI_getCityImportance(bool bEconomy, bool bMilitary);

	int AI_calculateMilitaryOutput() const; // K-Mod

	int AI_yieldMultiplier(YieldTypes eYield) const;
	void AI_updateSpecialYieldMultiplier();
	int AI_specialYieldMultiplier(YieldTypes eYield) const;

	int AI_countNumBonuses(BonusTypes eBonus, bool bIncludeOurs, bool bIncludeNeutral, int iOtherCultureThreshold, bool bLand = true, bool bWater = true);
/************************************************************************************************/
/* BETTER_BTS_AI_MOD                      11/14/09                                jdog5000      */
/*                                                                                              */
/* City AI                                                                                      */
/************************************************************************************************/
	int AI_countNumImprovableBonuses( bool bIncludeNeutral, TechTypes eExtraTech = NO_TECH, bool bLand = true, bool bWater = false );
/************************************************************************************************/
/* BETTER_BTS_AI_MOD                       END                                                  */
/************************************************************************************************/

	int AI_playerCloseness(PlayerTypes eIndex, int iMaxDistance);
	int AI_cityThreat(bool bDangerPercent = false);

	int AI_getWorkersHave();
	int AI_getWorkersNeeded();
	void AI_changeWorkersHave(int iChange);
	BuildingTypes AI_bestAdvancedStartBuilding(int iPass);

	void read(FDataStreamBase* pStream);
	void write(FDataStreamBase* pStream);

	void AI_ClearConstructionValueCache(); // K-Mod

protected:

	int m_iEmphasizeAvoidGrowthCount;
	int m_iEmphasizeGreatPeopleCount;

	bool m_bAssignWorkDirty;
	bool m_bChooseProductionDirty;

	IDInfo m_routeToCity;

	int* m_aiEmphasizeYieldCount;
	int* m_aiEmphasizeCommerceCount;
	bool m_bForceEmphasizeCulture;

	int m_aiBestBuildValue[NUM_CITY_PLOTS];

	BuildTypes m_aeBestBuild[NUM_CITY_PLOTS];

	bool* m_pbEmphasize;

	int* m_aiSpecialYieldMultiplier;

	int m_iCachePlayerClosenessTurn;
	int m_iCachePlayerClosenessDistance;
	int* m_aiPlayerCloseness;

	int m_iNeededFloatingDefenders;
	int m_iNeededFloatingDefendersCacheTurn;

	int m_iWorkersNeeded;
	int m_iWorkersHave;

	std::vector<int> m_aiConstructionValue; // K-Mod. (cache)

	void AI_doDraft(bool bForce = false);
	void AI_doHurry(bool bForce = false);
	void AI_doEmphasize();
	int AI_getHappyFromHurry(HurryTypes eHurry) const;
	int AI_getHappyFromHurry(HurryTypes eHurry, UnitTypes eUnit, bool bIgnoreNew) const;
	int AI_getHappyFromHurry(HurryTypes eHurry, BuildingTypes eBuilding, bool bIgnoreNew) const;
	int AI_getHappyFromHurry(int iHurryPopulation) const;
	bool AI_doPanic();
	int AI_calculateCulturePressure(bool bGreatWork = false) const;

/************************************************************************************************/
/* BETTER_BTS_AI_MOD                      01/09/10                                jdog5000      */
/*                                                                                              */
/* City AI                                                                                      */
/************************************************************************************************/
	bool AI_chooseUnit(UnitAITypes eUnitAI = NO_UNITAI, int iOdds = -1);
	bool AI_chooseUnit(UnitTypes eUnit, UnitAITypes eUnitAI);
	
	bool AI_chooseDefender();
	bool AI_chooseLeastRepresentedUnit(UnitTypeWeightArray &allowedTypes, int iOdds = -1);
	bool AI_chooseBuilding(int iFocusFlags = 0, int iMaxTurns = MAX_INT, int iMinThreshold = 0, int iOdds = -1);
	bool AI_chooseProject();
	bool AI_chooseProcess(CommerceTypes eCommerceType = NO_COMMERCE);
/************************************************************************************************/
/* BETTER_BTS_AI_MOD                       END                                                  */
/************************************************************************************************/

	bool AI_bestSpreadUnit(bool bMissionary, bool bExecutive, int iBaseChance, UnitTypes* eBestSpreadUnit, int* iBestSpreadUnitValue);
	bool AI_addBestCitizen(bool bWorkers, bool bSpecialists, int* piBestPlot = NULL, SpecialistTypes* peBestSpecialist = NULL);
	bool AI_removeWorstCitizen(SpecialistTypes eIgnoreSpecialist = NO_SPECIALIST);
	void AI_juggleCitizens();

	bool AI_potentialPlot(short* piYields) const;
	bool AI_foodAvailable(int iExtra = 0) const;
	int AI_yieldValue(short* piYields, short* piCommerceYields, bool bAvoidGrowth, bool bRemove, bool bIgnoreFood = false, bool bIgnoreGrowth = false, bool bIgnoreStarvation = false, bool bWorkerOptimization = false) const;
	int AI_plotValue(CvPlot* pPlot, bool bAvoidGrowth, bool bRemove, bool bIgnoreFood = false, bool bIgnoreGrowth = false, bool bIgnoreStarvation = false) const;

	int AI_experienceWeight();
	int AI_buildUnitProb();

	void AI_bestPlotBuild(CvPlot* pPlot, int* piBestValue, BuildTypes* peBestBuild, int iFoodPriority, int iProductionPriority, int iCommercePriority, bool bChop, int iHappyAdjust, int iHealthAdjust, int iFoodChange);

	void AI_buildGovernorChooseProduction();
	
	int AI_getYieldMagicValue(const int* piYieldsTimes100, bool bHealthy) const;
	int AI_getPlotMagicValue(CvPlot* pPlot, bool bHealthy, bool bWorkerOptimization = false) const;
	int AI_countGoodTiles(bool bHealthy, bool bUnworkedOnly, int iThreshold = 50, bool bWorkerOptimization = false) const;
	int AI_countGoodSpecialists(bool bHealthy) const;
	int AI_calculateTargetCulturePerTurn() const;
	
	void AI_stealPlots();
	
	int AI_buildingSpecialYieldChangeValue(BuildingTypes kBuilding, YieldTypes eYield) const;
	
	void AI_cachePlayerCloseness(int iMaxDistance);
	void AI_updateWorkersNeededHere();

	// added so under cheat mode we can call protected functions for testing
	friend class CvGameTextMgr;
};

#endif
