# dmstlcomp

Copyright (c) 2013-2018 brinkqiang (brink.qiang@gmail.com)

[![dmstlcomp](https://img.shields.io/badge/brinkqiang-dmstlcomp-blue.svg?style=flat-square)](https://github.com/brinkqiang/dmstlcomp)
[![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](https://github.com/brinkqiang/dmstlcomp/blob/master/LICENSE)
[![blog](https://img.shields.io/badge/Author-Blog-7AD6FD.svg)](https://brinkqiang.github.io/)
[![Open Source Love](https://badges.frapsoft.com/os/v3/open-source.png)](https://github.com/brinkqiang)
[![GitHub stars](https://img.shields.io/github/stars/brinkqiang/dmstlcomp.svg?label=Stars)](https://github.com/brinkqiang/dmstlcomp) 
[![GitHub forks](https://img.shields.io/github/forks/brinkqiang/dmstlcomp.svg?label=Fork)](https://github.com/brinkqiang/dmstlcomp)

## Build status
| [Linux][lin-link] | [Mac][mac-link] | [Windows][win-link] |
| :---------------: | :----------------: | :-----------------: |
| ![lin-badge]      | ![mac-badge]       | ![win-badge]        |

[lin-badge]: https://github.com/brinkqiang/dmstlcomp/workflows/linux/badge.svg "linux build status"
[lin-link]:  https://github.com/brinkqiang/dmstlcomp/actions/workflows/linux.yml "linux build status"
[mac-badge]: https://github.com/brinkqiang/dmstlcomp/workflows/mac/badge.svg "mac build status"
[mac-link]:  https://github.com/brinkqiang/dmstlcomp/actions/workflows/mac.yml "mac build status"
[win-badge]: https://github.com/brinkqiang/dmstlcomp/workflows/win/badge.svg "win build status"
[win-link]:  https://github.com/brinkqiang/dmstlcomp/actions/workflows/win.yml "win build status"

## Intro
dmstlcomp
```cpp


#include "dmstlcomp.h"
#include "dmformat.h"
#include <algorithm>
#include <iomanip>

typedef struct tagData
{
    tagData(std::string _strName, int _nID, int _nData) : strName(_strName), nID(_nID), nData(_nData){}

    std::string& GetName(){ return strName; }
    int& GetID(){ return nID; }
    std::string     strName;
    int             nID;
    int             nData;

    template<class Os> friend
        Os& operator<< (Os& os, tagData const& p) {
        return os << "\n" << fmt::format("[{}] [{}] [{}]", p.strName, p.nID, p.nData);
    }
}SData;

void print(auto const& seq) {
    for (auto const& elem : seq) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}

struct Particle {
    std::string name; double mass; // MeV
    template<class Os> friend
        Os& operator<< (Os& os, Particle const& p) {
        return os << "\n" << std::left
            << std::setw(8) << p.name
            << " : " << p.mass;
    }
};

int main(int argc, char* argv[])
{
    std::vector<SData> vecABC;

    vecABC.emplace_back(SData("a1", 22, 11));
    vecABC.emplace_back(SData("b2", 1, 21));
    vecABC.emplace_back(SData("c3", 22, 12));
    vecABC.emplace_back(SData("d4", 2, 22));
    vecABC.emplace_back(SData("e5", 22, 13));
    vecABC.emplace_back(SData("f6", 3, 23));

    vecABC.emplace_back(SData("g7", 23, 11));
    vecABC.emplace_back(SData("g8", 4, 21));
    vecABC.emplace_back(SData("g9", 6, 12));
    vecABC.emplace_back(SData("h10", 5, 22));
    vecABC.emplace_back(SData("i11", 12, 13));
    vecABC.emplace_back(SData("j12", 7, 23));

    std::ranges::sort(vecABC, {}, &SData::nData);

    print(vecABC);

    std::sort(vecABC.begin(), vecABC.end(), PP_COMBINECOMP_GREATER_V2(&SData::nData, &SData::GetID));

    print(vecABC);
    std::sort(vecABC.begin(), vecABC.end(), PP_COMBINECOMP_LESS_V2(&SData::nData, &SData::GetID));

    print(vecABC);

    return (0);
}
```
## Contacts

## Thanks
