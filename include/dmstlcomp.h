#ifndef __UTILCOMP_H_INCLUDE__
#define __UTILCOMP_H_INCLUDE__

#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

template<class V, class T>
struct comp_equal
{
    typedef T op_type;
    comp_equal(V T::*fun){m_fun=fun;}
    V T::*m_fun;
    bool operator()(T& left, T& right)
    {
        return left.*m_fun == right.*m_fun;
    }
};

template<class V, class T>
struct comp_equal_func
{
    typedef T op_type;
    comp_equal_func(V (T::*fun)()){m_fun=fun;}
    V (T::*m_fun)();
    bool operator()(T& left, T& right)
    {
        return (left.*m_fun)() == (right.*m_fun)();
    }
};

template<class V, class T>
struct comp_less
{
    typedef T op_type;
    comp_less(V T::*fun){m_fun=fun;}
    V T::*m_fun;
    bool operator()(T& left, T& right)
    {
        return left.*m_fun < right.*m_fun;
    }
};

template<class V, class T>
struct comp_less_func
{
    typedef T op_type;
    comp_less_func(V (T::*fun)()){m_fun=fun;}
    V (T::*m_fun)();
    bool operator()(T& left, T& right)
    {
        return (left.*m_fun)() < (right.*m_fun)();
    }
};

template<class V, class T>
struct comp_greater
{
    typedef T op_type;
    comp_greater(V T::*fun){m_fun=fun;}
    V T::*m_fun;
    bool operator()(const T& left, const T& right)
    {
        return left.*m_fun > right.*m_fun;
    }
};

template<class V, class T>
struct comp_greater_func
{
    typedef T op_type;
    comp_greater_func(V (T::*fun)()){m_fun=fun;}
    V (T::*m_fun)();
    bool operator()(T& left, T& right)
    {
        return (left.*m_fun)() > (right.*m_fun)();
    }
};

template<typename comp1, typename comp2>
struct combine_comp_f
{
    typedef typename comp1::op_type op_type;
    combine_comp_f(comp1 c1, comp2 c2)
        : m_c1(c1), m_c2(c2)
    {
    }

    bool operator()(op_type &left, op_type &right)
    {
        if (!m_c1(left,right) && !m_c1(right,left))
          return m_c2(left,right);
        return m_c1(left,right);
    }

    bool operator()(op_type* left_ptr, op_type* right_ptr)
    {
        if (!m_c1(*left_ptr,*right_ptr) && !m_c1(*right_ptr,*left_ptr))
          return m_c2(*left_ptr,*right_ptr);
        return m_c1(*left_ptr,*right_ptr);
    }

    comp1 m_c1;
    comp2 m_c2;
};

template<class V, class T>
comp_equal<V,T> create_comp_equal(V T::*fun)
{
    return comp_equal<V,T>(fun);
}

template<class V, class T>
comp_equal_func<V,T> create_comp_equal(V (T::*fun)())
{
    return comp_equal_func<V,T>(fun);
}

template<class V, class T>
comp_less<V,T> create_comp_less(V T::*fun)
{
    return comp_less<V,T>(fun);
}

template<class V, class T>
comp_less_func<V,T> create_comp_less(V (T::*fun)())
{
    return comp_less_func<V,T>(fun);
}

template<class V, class T>
comp_greater<V,T> create_comp_greater(V T::*fun)
{
    return comp_greater<V,T>(fun);
}

template<class V, class T>
comp_greater_func<V,T> create_comp_greater(V (T::*fun)())
{
    return comp_greater_func<V,T>(fun);
}

template<class C1, class C2>
combine_comp_f<C1, C2> combine_comp(C1 c1, C2 c2)
{
    return combine_comp_f<C1,C2>(c1, c2);
}

template<class container>
void
print_container(const container& c)
{
    std::copy(c.begin(), c.end(), std::ostream_iterator<typename container::value_type>(std::cout, std::endl));
}

#define PP_COMBINECOMP_LESS_V0                                           combine_comp
#define PP_COMBINECOMP_LESS_V1(_A)                                       create_comp_less(_A)
#define PP_COMBINECOMP_LESS_V2(_A, _B)                                   PP_COMBINECOMP_LESS_V0(PP_COMBINECOMP_LESS_V1(_A),                  PP_COMBINECOMP_LESS_V1(_B))
#define PP_COMBINECOMP_LESS_V3(_A, _B, _C)                               PP_COMBINECOMP_LESS_V0(PP_COMBINECOMP_LESS_V2(_A, _B),              PP_COMBINECOMP_LESS_V1(_C))
#define PP_COMBINECOMP_LESS_V4(_A, _B, _C, _D)                           PP_COMBINECOMP_LESS_V0(PP_COMBINECOMP_LESS_V2(_A, _B),              PP_COMBINECOMP_LESS_V2(_C, _D))
#define PP_COMBINECOMP_LESS_V5(_A, _B, _C, _D, _E)                       PP_COMBINECOMP_LESS_V0(PP_COMBINECOMP_LESS_V3(_A, _B, _C),          PP_COMBINECOMP_LESS_V2(_D, _E))
#define PP_COMBINECOMP_LESS_V6(_A, _B, _C, _D, _E, _F)                   PP_COMBINECOMP_LESS_V0(PP_COMBINECOMP_LESS_V3(_A, _B, _C),          PP_COMBINECOMP_LESS_V3(_D, _E, _F))
#define PP_COMBINECOMP_LESS_V7(_A, _B, _C, _D, _E, _F, _G)               PP_COMBINECOMP_LESS_V0(PP_COMBINECOMP_LESS_V4(_A, _B, _C, _D),      PP_COMBINECOMP_LESS_V3(_E, _F, _G))
#define PP_COMBINECOMP_LESS_V8(_A, _B, _C, _D, _E, _F, _G, _H)           PP_COMBINECOMP_LESS_V0(PP_COMBINECOMP_LESS_V4(_A, _B, _C, _D),      PP_COMBINECOMP_LESS_V4(_E, _F, _G, _H))
#define PP_COMBINECOMP_LESS_V9(_A, _B, _C, _D, _E, _F, _G, _H, _I)       PP_COMBINECOMP_LESS_V0(PP_COMBINECOMP_LESS_V5(_A, _B, _C, _D, _E),  PP_COMBINECOMP_LESS_V4(_F, _G, _H, _I))
#define PP_COMBINECOMP_LESS_V10(_A, _B, _C, _D, _E, _F, _G, _H, _I, _J)  PP_COMBINECOMP_LESS_V0(PP_COMBINECOMP_LESS_V5(_A, _B, _C, _D, _E),  PP_COMBINECOMP_LESS_V5(_F, _G, _H, _I, _J))

#define PP_COMBINECOMP_GREATER_V0                                           combine_comp
#define PP_COMBINECOMP_GREATER_V1(_A)                                       create_comp_greater(_A)
#define PP_COMBINECOMP_GREATER_V2(_A, _B)                                   PP_COMBINECOMP_GREATER_V0(PP_COMBINECOMP_GREATER_V1(_A),                  PP_COMBINECOMP_GREATER_V1(_B))
#define PP_COMBINECOMP_GREATER_V3(_A, _B, _C)                               PP_COMBINECOMP_GREATER_V0(PP_COMBINECOMP_GREATER_V2(_A, _B),              PP_COMBINECOMP_GREATER_V1(_C))
#define PP_COMBINECOMP_GREATER_V4(_A, _B, _C, _D)                           PP_COMBINECOMP_GREATER_V0(PP_COMBINECOMP_GREATER_V2(_A, _B),              PP_COMBINECOMP_GREATER_V2(_C, _D))
#define PP_COMBINECOMP_GREATER_V5(_A, _B, _C, _D, _E)                       PP_COMBINECOMP_GREATER_V0(PP_COMBINECOMP_GREATER_V3(_A, _B, _C),          PP_COMBINECOMP_GREATER_V2(_D, _E))
#define PP_COMBINECOMP_GREATER_V6(_A, _B, _C, _D, _E, _F)                   PP_COMBINECOMP_GREATER_V0(PP_COMBINECOMP_GREATER_V3(_A, _B, _C),          PP_COMBINECOMP_GREATER_V3(_D, _E, _F))
#define PP_COMBINECOMP_GREATER_V7(_A, _B, _C, _D, _E, _F, _G)               PP_COMBINECOMP_GREATER_V0(PP_COMBINECOMP_GREATER_V4(_A, _B, _C, _D),      PP_COMBINECOMP_GREATER_V3(_E, _F, _G))
#define PP_COMBINECOMP_GREATER_V8(_A, _B, _C, _D, _E, _F, _G, _H)           PP_COMBINECOMP_GREATER_V0(PP_COMBINECOMP_GREATER_V4(_A, _B, _C, _D),      PP_COMBINECOMP_GREATER_V4(_E, _F, _G, _H))
#define PP_COMBINECOMP_GREATER_V9(_A, _B, _C, _D, _E, _F, _G, _H, _I)       PP_COMBINECOMP_GREATER_V0(PP_COMBINECOMP_GREATER_V5(_A, _B, _C, _D, _E),  PP_COMBINECOMP_GREATER_V4(_F, _G, _H, _I))
#define PP_COMBINECOMP_GREATER_V10(_A, _B, _C, _D, _E, _F, _G, _H, _I, _J)  PP_COMBINECOMP_GREATER_V0(PP_COMBINECOMP_GREATER_V5(_A, _B, _C, _D, _E),  PP_COMBINECOMP_GREATER_V5(_F, _G, _H, _I, _J))

#define PP_COMBINECOMP_EQUAL_V0                                           combine_comp
#define PP_COMBINECOMP_EQUAL_V1(_A)                                       create_comp_equal(_A)

//typedef struct tagData
//{
//    tagData(std::string _strName, int _nID, int _nData): strName(_strName), nID(_nID), nData(_nData){}
//
//    std::string&    GetName(){ return strName;}
//    int& GetID(){ return nID;}
//    std::string     strName;
//    int             nID;
//    int             nData;
//}SData;
//
//int main(int argc, char* argv[])
//{
//    std::vector<SData> vecABC;
//
//    vecABC.push_back(SData("a1", 22, 11));
//    vecABC.push_back(SData("b2", 1, 21));
//    vecABC.push_back(SData("c3", 22, 12));
//    vecABC.push_back(SData("d4", 2, 22));
//    vecABC.push_back(SData("e5", 22, 13));
//    vecABC.push_back(SData("f6", 3, 23));
//
//    vecABC.push_back(SData("g7", 23, 11));
//    vecABC.push_back(SData("g8", 4, 21));
//    vecABC.push_back(SData("g9", 6, 12));
//    vecABC.push_back(SData("h10", 5, 22));
//    vecABC.push_back(SData("i11", 12, 13));
//    vecABC.push_back(SData("j12", 7, 23));
//
//    std::sort(vecABC.begin(), vecABC.end(), PP_COMBINECOMP_LESS_V1(&SData::nData));
//
//    std::sort(vecABC.begin(), vecABC.end(), PP_COMBINECOMP_GREATER_V2(&SData::nData, &SData::GetID));
//    std::sort(vecABC.begin(), vecABC.end(), PP_COMBINECOMP_LESS_V2(&SData::nData, &SData::GetID));
//    return (0);
//}
#endif // __UTILCOMP_H_INCLUDE__

