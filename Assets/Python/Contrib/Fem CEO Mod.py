## Female CEO Mod.py  08/22/10 - Lemon Merchant
## Allows the use of Saibotlieh's Female Missionary and CEO Units in the BAT Mod 
## This is a BUG module, and requires the BUG mod for use.


from CvPythonExtensions import *
import CvUtil
import CvScreensInterface
import PyHelpers
import Popup as PyPopup
import CvCameraControls
import CvTopCivs
import sys
import CvAdvisorUtils
import CvTechChooser

gc = CyGlobalContext()
localText = CyTranslator()
PyPlayer = PyHelpers.PyPlayer
PyInfo = PyHelpers.PyInfo


def onUnitBuilt(argsList):
		'Unit Completed'
		city = argsList[0]
		unit = argsList[1]
		player = PyPlayer(city.getOwner())
		iplayer = gc.getPlayer(city.getOwner())
		
# Female CEO begin

		iUnitType = unit.getUnitType()
		UnitInfo = gc.getUnitInfo(iUnitType)
		sUnitType = UnitInfo.getType()
	
		if UnitInfo.getDefaultUnitAIType() == gc.getInfoTypeForString('UNITAI_MISSIONARY'):
			sUnitBuilt = gc.getInfoTypeForString(sUnitType[:20])
			
			if sUnitBuilt == "UNITCLASS_EXECUTIVE_":
				sCEOType = gc.getInfoTypeForString(sUnitType[20:])
				iFemaleUnitType = CvUtil.findInfoTypeNum(gc.getUnitInfo,gc.getNumUnitInfos(),sUnitBuilt+sCEOType+'_FEMALE')
				
			else:		
				sFemaleUnitType = 'UNIT_FEMALE'+sUnitType[4:]
				iFemaleUnitType = gc.getInfoTypeForString(sFemaleUnitType)
			
			iRnd = CyGame().getSorenRandNum(100, "female CEO")
			if iplayer.isCivic(gc.getInfoTypeForString("CIVIC_EMANCIPATION")):
				iRnd -= 35
			if iRnd <= 20:	## Changed from 15 to 20 - better chance of generating female unit without Emancipation
				oldunit = unit				
				pFemaleUnit = iplayer.initUnit(iFemaleUnitType,oldunit.getX(),oldunit.getY(),UnitAITypes.NO_UNITAI,DirectionTypes.DIRECTION_SOUTH)
				pFemaleUnit.convert(oldunit)
				if oldunit.getGroup().isAutomated():
					pFemaleUnit.getGroup().setAutomateType(AutomateTypes.AUTOMATE_RELIGION)
				oldunit.kill(false,oldunit.getOwner())
				
# End Female CEO code

		CvAdvisorUtils.unitBuiltFeats(city, unit)
				
		 
