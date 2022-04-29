

#include "dmstlcomp.h"
#include "dmformat.h"

typedef struct tagData
{
   tagData(std::string _strName, int _nID, int _nData): strName(_strName), nID(_nID), nData(_nData){}

   std::string&    GetName(){ return strName;}
   int& GetID(){ return nID;}
   std::string     strName;
   int             nID;
   int             nData;
}SData;

int main(int argc, char* argv[])
{
   std::vector<SData> vecABC;

   vecABC.push_back(SData("a1", 22, 11));
   vecABC.push_back(SData("b2", 1, 21));
   vecABC.push_back(SData("c3", 22, 12));
   vecABC.push_back(SData("d4", 2, 22));
   vecABC.push_back(SData("e5", 22, 13));
   vecABC.push_back(SData("f6", 3, 23));

   vecABC.push_back(SData("g7", 23, 11));
   vecABC.push_back(SData("g8", 4, 21));
   vecABC.push_back(SData("g9", 6, 12));
   vecABC.push_back(SData("h10", 5, 22));
   vecABC.push_back(SData("i11", 12, 13));
   vecABC.push_back(SData("j12", 7, 23));

   std::sort(vecABC.begin(), vecABC.end(), PP_COMBINECOMP_LESS_V1(&SData::nData));

   std::sort(vecABC.begin(), vecABC.end(), PP_COMBINECOMP_GREATER_V2(&SData::nData, &SData::GetID));
   std::sort(vecABC.begin(), vecABC.end(), PP_COMBINECOMP_LESS_V2(&SData::nData, &SData::GetID));
   return (0);
}