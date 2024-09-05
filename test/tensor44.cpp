////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <boost/ut.hpp>
#include <yq-toolbox/math/tolerance/Absolute.hpp>
#include <yq-toolbox/math/utility.hpp>
#include <yq-toolbox/tensor/Tensor44.hxx>

namespace ut = boost::ut;
using namespace ut;
using namespace yq;

int main()
{
    //Absolute tol{1e-12};

    "zero is zero"_test = []{
        expect( true == (Tensor44U(ZERO) == Tensor44U(ZERO)));
        expect( true == (Tensor44D(ZERO) == Tensor44D(ZERO)));
        expect( true == (Tensor44F(ZERO) == Tensor44F(ZERO)));
        expect( true == (all(Tensor44F(ZERO)) == 0.f));
    };
    
    "addition"_test = []{

        // Uniform
        expect(
            Tensor44I(
                1,1,1,1,
                1,1,1,1,
                1,1,1,1,
                1,1,1,1
            ) + Tensor44I(ALL,2) ==  Tensor44I(
                3,3,3,3,
                3,3,3,3,
                3,3,3,3,
                3,3,3,3
            )
        );
        
        //  XX
        expect(
            Tensor44I(
                2,1,1,1,
                1,1,1,1,
                1,1,1,1,
                1,1,1,1
            ) + Tensor44I(ALL,2) ==  Tensor44I(
                4,3,3,3,
                3,3,3,3,
                3,3,3,3,
                3,3,3,3
            )
        );

        //  XY
        expect(
            Tensor44I(
                1,2,1,1,
                1,1,1,1,
                1,1,1,1,
                1,1,1,1
            ) + Tensor44I(ALL,2) ==  Tensor44I(
                3,4,3,3,
                3,3,3,3,
                3,3,3,3,
                3,3,3,3
            )
        );

        //  XZ
        expect(
            Tensor44I(
                1,1,2,1,
                1,1,1,1,
                1,1,1,1,
                1,1,1,1
            ) + Tensor44I(ALL,2) ==  Tensor44I(
                3,3,4,3,
                3,3,3,3,
                3,3,3,3,
                3,3,3,3
            )
        );

        //  XW
        expect(
            Tensor44I(
                1,1,1,2,
                1,1,1,1,
                1,1,1,1,
                1,1,1,1
            ) + Tensor44I(ALL,2) ==  Tensor44I(
                3,3,3,4,
                3,3,3,3,
                3,3,3,3,
                3,3,3,3
            )
        );

        //  YX
        expect(
            Tensor44I(
                1,1,1,1,
                2,1,1,1,
                1,1,1,1,
                1,1,1,1
            ) + Tensor44I(ALL,2) ==  Tensor44I(
                3,3,3,3,
                4,3,3,3,
                3,3,3,3,
                3,3,3,3
            )
        );

        //  YY
        expect(
            Tensor44I(
                1,1,1,1,
                1,2,1,1,
                1,1,1,1,
                1,1,1,1
            ) + Tensor44I(ALL,2) ==  Tensor44I(
                3,3,3,3,
                3,4,3,3,
                3,3,3,3,
                3,3,3,3
            )
        );

        //  YZ
        expect(
            Tensor44I(
                1,1,1,1,
                1,1,2,1,
                1,1,1,1,
                1,1,1,1
            ) + Tensor44I(ALL,2) ==  Tensor44I(
                3,3,3,3,
                3,3,4,3,
                3,3,3,3,
                3,3,3,3
            )
        );

        //  YW
        expect(
            Tensor44I(
                1,1,1,1,
                1,1,1,2,
                1,1,1,1,
                1,1,1,1
            ) + Tensor44I(ALL,2) ==  Tensor44I(
                3,3,3,3,
                3,3,3,4,
                3,3,3,3,
                3,3,3,3
            )
        );

        //  ZX
        expect(
            Tensor44I(
                1,1,1,1,
                1,1,1,1,
                2,1,1,1,
                1,1,1,1
            ) + Tensor44I(ALL,2) ==  Tensor44I(
                3,3,3,3,
                3,3,3,3,
                4,3,3,3,
                3,3,3,3
            )
        );

        //  ZY
        expect(
            Tensor44I(
                1,1,1,1,
                1,1,1,1,
                1,2,1,1,
                1,1,1,1
            ) + Tensor44I(ALL,2) ==  Tensor44I(
                3,3,3,3,
                3,3,3,3,
                3,4,3,3,
                3,3,3,3
            )
        );

        //  ZZ
        expect(
            Tensor44I(
                1,1,1,1,
                1,1,1,1,
                1,1,2,1,
                1,1,1,1
            ) + Tensor44I(ALL,2) ==  Tensor44I(
                3,3,3,3,
                3,3,3,3,
                3,3,4,3,
                3,3,3,3
            )
        );

        //  ZW
        expect(
            Tensor44I(
                1,1,1,1,
                1,1,1,1,
                1,1,1,2,
                1,1,1,1
            ) + Tensor44I(ALL,2) ==  Tensor44I(
                3,3,3,3,
                3,3,3,3,
                3,3,3,4,
                3,3,3,3
            )
        );

        //  WX
        expect(
            Tensor44I(
                1,1,1,1,
                1,1,1,1,
                1,1,1,1,
                2,1,1,1
            ) + Tensor44I(ALL,2) ==  Tensor44I(
                3,3,3,3,
                3,3,3,3,
                3,3,3,3,
                4,3,3,3
            )
        );

        //  WY
        expect(
            Tensor44I(
                1,1,1,1,
                1,1,1,1,
                1,1,1,1,
                1,2,1,1
            ) + Tensor44I(ALL,2) ==  Tensor44I(
                3,3,3,3,
                3,3,3,3,
                3,3,3,3,
                3,4,3,3
            )
        );

        //  WZ
        expect(
            Tensor44I(
                1,1,1,1,
                1,1,1,1,
                1,1,1,1,
                1,1,2,1
            ) + Tensor44I(ALL,2) ==  Tensor44I(
                3,3,3,3,
                3,3,3,3,
                3,3,3,3,
                3,3,4,3
            )
        );

        //  WW
        expect(
            Tensor44I(
                1,1,1,1,
                1,1,1,1,
                1,1,1,1,
                1,1,1,2
            ) + Tensor44I(ALL,2) ==  Tensor44I(
                3,3,3,3,
                3,3,3,3,
                3,3,3,3,
                3,3,3,4
            )
        );
    };

    "subtraction"_test = []{

        // Uniform
        expect(
            Tensor44I(
                +1,+1,+1,+1,
                +1,+1,+1,+1,
                +1,+1,+1,+1,
                +1,+1,+1,+1
            ) - Tensor44I(ALL,2) ==  Tensor44I(
                -1,-1,-1,-1,
                -1,-1,-1,-1,
                -1,-1,-1,-1,
                -1,-1,-1,-1
            )
        );

        // XX
        expect(
            Tensor44I(
                -1,+1,+1,+1,
                +1,+1,+1,+1,
                +1,+1,+1,+1,
                +1,+1,+1,+1
            ) - Tensor44I(ALL,2) ==  Tensor44I(
                -3,-1,-1,-1,
                -1,-1,-1,-1,
                -1,-1,-1,-1,
                -1,-1,-1,-1
            )
        );

        // XY
        expect(
            Tensor44I(
                +1,-1,+1,+1,
                +1,+1,+1,+1,
                +1,+1,+1,+1,
                +1,+1,+1,+1
            ) - Tensor44I(ALL,2) ==  Tensor44I(
                -1,-3,-1,-1,
                -1,-1,-1,-1,
                -1,-1,-1,-1,
                -1,-1,-1,-1
            )
        );

        // XZ
        expect(
            Tensor44I(
                +1,+1,-1,+1,
                +1,+1,+1,+1,
                +1,+1,+1,+1,
                +1,+1,+1,+1
            ) - Tensor44I(ALL,2) ==  Tensor44I(
                -1,-1,-3,-1,
                -1,-1,-1,-1,
                -1,-1,-1,-1,
                -1,-1,-1,-1
            )
        );

        // XW
        expect(
            Tensor44I(
                +1,+1,+1,-1,
                +1,+1,+1,+1,
                +1,+1,+1,+1,
                +1,+1,+1,+1
            ) - Tensor44I(ALL,2) ==  Tensor44I(
                -1,-1,-1,-3,
                -1,-1,-1,-1,
                -1,-1,-1,-1,
                -1,-1,-1,-1
            )
        );

        // YX
        expect(
            Tensor44I(
                +1,+1,+1,+1,
                -1,+1,+1,+1,
                +1,+1,+1,+1,
                +1,+1,+1,+1
            ) - Tensor44I(ALL,2) ==  Tensor44I(
                -1,-1,-1,-1,
                -3,-1,-1,-1,
                -1,-1,-1,-1,
                -1,-1,-1,-1
            )
        );

        // YY
        expect(
            Tensor44I(
                +1,+1,+1,+1,
                +1,-1,+1,+1,
                +1,+1,+1,+1,
                +1,+1,+1,+1
            ) - Tensor44I(ALL,2) ==  Tensor44I(
                -1,-1,-1,-1,
                -1,-3,-1,-1,
                -1,-1,-1,-1,
                -1,-1,-1,-1
            )
        );

        // YZ
        expect(
            Tensor44I(
                +1,+1,+1,+1,
                +1,+1,-1,+1,
                +1,+1,+1,+1,
                +1,+1,+1,+1
            ) - Tensor44I(ALL,2) ==  Tensor44I(
                -1,-1,-1,-1,
                -1,-1,-3,-1,
                -1,-1,-1,-1,
                -1,-1,-1,-1
            )
        );

        // YW
        expect(
            Tensor44I(
                +1,+1,+1,+1,
                +1,+1,+1,-1,
                +1,+1,+1,+1,
                +1,+1,+1,+1
            ) - Tensor44I(ALL,2) ==  Tensor44I(
                -1,-1,-1,-1,
                -1,-1,-1,-3,
                -1,-1,-1,-1,
                -1,-1,-1,-1
            )
        );

        // ZX
        expect(
            Tensor44I(
                +1,+1,+1,+1,
                +1,+1,+1,+1,
                -1,+1,+1,+1,
                +1,+1,+1,+1
            ) - Tensor44I(ALL,2) ==  Tensor44I(
                -1,-1,-1,-1,
                -1,-1,-1,-1,
                -3,-1,-1,-1,
                -1,-1,-1,-1
            )
        );

        // ZY
        expect(
            Tensor44I(
                +1,+1,+1,+1,
                +1,+1,+1,+1,
                +1,-1,+1,+1,
                +1,+1,+1,+1
            ) - Tensor44I(ALL,2) ==  Tensor44I(
                -1,-1,-1,-1,
                -1,-1,-1,-1,
                -1,-3,-1,-1,
                -1,-1,-1,-1
            )
        );

        // ZZ
        expect(
            Tensor44I(
                +1,+1,+1,+1,
                +1,+1,+1,+1,
                +1,+1,-1,+1,
                +1,+1,+1,+1
            ) - Tensor44I(ALL,2) ==  Tensor44I(
                -1,-1,-1,-1,
                -1,-1,-1,-1,
                -1,-1,-3,-1,
                -1,-1,-1,-1
            )
        );

        // ZW
        expect(
            Tensor44I(
                +1,+1,+1,+1,
                +1,+1,+1,+1,
                +1,+1,+1,-1,
                +1,+1,+1,+1
            ) - Tensor44I(ALL,2) ==  Tensor44I(
                -1,-1,-1,-1,
                -1,-1,-1,-1,
                -1,-1,-1,-3,
                -1,-1,-1,-1
            )
        );
        
        // WX
        expect(
            Tensor44I(
                +1,+1,+1,+1,
                +1,+1,+1,+1,
                +1,+1,+1,+1,
                -1,+1,+1,+1
            ) - Tensor44I(ALL,2) ==  Tensor44I(
                -1,-1,-1,-1,
                -1,-1,-1,-1,
                -1,-1,-1,-1,
                -3,-1,-1,-1
            )
        );

        // WY
        expect(
            Tensor44I(
                +1,+1,+1,+1,
                +1,+1,+1,+1,
                +1,+1,+1,+1,
                +1,-1,+1,+1
            ) - Tensor44I(ALL,2) ==  Tensor44I(
                -1,-1,-1,-1,
                -1,-1,-1,-1,
                -1,-1,-1,-1,
                -1,-3,-1,-1
            )
        );

        // WZ
        expect(
            Tensor44I(
                +1,+1,+1,+1,
                +1,+1,+1,+1,
                +1,+1,+1,+1,
                +1,+1,-1,+1
            ) - Tensor44I(ALL,2) ==  Tensor44I(
                -1,-1,-1,-1,
                -1,-1,-1,-1,
                -1,-1,-1,-1,
                -1,-1,-3,-1
            )
        );

        // WW
        expect(
            Tensor44I(
                +1,+1,+1,+1,
                +1,+1,+1,+1,
                +1,+1,+1,+1,
                +1,+1,+1,-1
            ) - Tensor44I(ALL,2) ==  Tensor44I(
                -1,-1,-1,-1,
                -1,-1,-1,-1,
                -1,-1,-1,-1,
                -1,-1,-1,-3
            )
        );
    };
    
    "Multiply-int"_test = []{
        // uniform
        expect(
            Tensor44I(
                1,1,1,1,
                1,1,1,1,
                1,1,1,1,
                1,1,1,1
            ) * 3 ==  Tensor44I(
                3,3,3,3,
                3,3,3,3,
                3,3,3,3,
                3,3,3,3
            )
        );
        
        // XX
        expect(
            Tensor44I(
                2,1,1,1,
                1,1,1,1,
                1,1,1,1,
                1,1,1,1
            ) * 3 ==  Tensor44I(
                6,3,3,3,
                3,3,3,3,
                3,3,3,3,
                3,3,3,3
            )
        );

        // XY
        expect(
            Tensor44I(
                1,2,1,1,
                1,1,1,1,
                1,1,1,1,
                1,1,1,1
            ) * 3 ==  Tensor44I(
                3,6,3,3,
                3,3,3,3,
                3,3,3,3,
                3,3,3,3
            )
        );

        // XZ
        expect(
            Tensor44I(
                1,1,2,1,
                1,1,1,1,
                1,1,1,1,
                1,1,1,1
            ) * 3 ==  Tensor44I(
                3,3,6,3,
                3,3,3,3,
                3,3,3,3,
                3,3,3,3
            )
        );

        // XW
        expect(
            Tensor44I(
                1,1,1,2,
                1,1,1,1,
                1,1,1,1,
                1,1,1,1
            ) * 3 ==  Tensor44I(
                3,3,3,6,
                3,3,3,3,
                3,3,3,3,
                3,3,3,3
            )
        );

        
        // YX
        expect(
            Tensor44I(
                1,1,1,1,
                2,1,1,1,
                1,1,1,1,
                1,1,1,1
            ) * 3 ==  Tensor44I(
                3,3,3,3,
                6,3,3,3,
                3,3,3,3,
                3,3,3,3
            )
        );

        // YY
        expect(
            Tensor44I(
                1,1,1,1,
                1,2,1,1,
                1,1,1,1,
                1,1,1,1
            ) * 3 ==  Tensor44I(
                3,3,3,3,
                3,6,3,3,
                3,3,3,3,
                3,3,3,3
            )
        );

        // YZ
        expect(
            Tensor44I(
                1,1,1,1,
                1,1,2,1,
                1,1,1,1,
                1,1,1,1
            ) * 3 ==  Tensor44I(
                3,3,3,3,
                3,3,6,3,
                3,3,3,3,
                3,3,3,3
            )
        );

        // YW
        expect(
            Tensor44I(
                1,1,1,1,
                1,1,1,2,
                1,1,1,1,
                1,1,1,1
            ) * 3 ==  Tensor44I(
                3,3,3,3,
                3,3,3,6,
                3,3,3,3,
                3,3,3,3
            )
        );

        
        // ZX
        expect(
            Tensor44I(
                1,1,1,1,
                1,1,1,1,
                2,1,1,1,
                1,1,1,1
            ) * 3 ==  Tensor44I(
                3,3,3,3,
                3,3,3,3,
                6,3,3,3,
                3,3,3,3
            )
        );

        // ZY
        expect(
            Tensor44I(
                1,1,1,1,
                1,1,1,1,
                1,2,1,1,
                1,1,1,1
            ) * 3 ==  Tensor44I(
                3,3,3,3,
                3,3,3,3,
                3,6,3,3,
                3,3,3,3
            )
        );

        // ZZ
        expect(
            Tensor44I(
                1,1,1,1,
                1,1,1,1,
                1,1,2,1,
                1,1,1,1
            ) * 3 ==  Tensor44I(
                3,3,3,3,
                3,3,3,3,
                3,3,6,3,
                3,3,3,3
            )
        );

        // ZW
        expect(
            Tensor44I(
                1,1,1,1,
                1,1,1,1,
                1,1,1,2,
                1,1,1,1
            ) * 3 ==  Tensor44I(
                3,3,3,3,
                3,3,3,3,
                3,3,3,6,
                3,3,3,3
            )
        );

        
        // WX
        expect(
            Tensor44I(
                1,1,1,1,
                1,1,1,1,
                1,1,1,1,
                2,1,1,1
            ) * 3 ==  Tensor44I(
                3,3,3,3,
                3,3,3,3,
                3,3,3,3,
                6,3,3,3
            )
        );

        // WY
        expect(
            Tensor44I(
                1,1,1,1,
                1,1,1,1,
                1,1,1,1,
                1,2,1,1
            ) * 3 ==  Tensor44I(
                3,3,3,3,
                3,3,3,3,
                3,3,3,3,
                3,6,3,3
            )
        );

        // WZ
        expect(
            Tensor44I(
                1,1,1,1,
                1,1,1,1,
                1,1,1,1,
                1,1,2,1
            ) * 3 ==  Tensor44I(
                3,3,3,3,
                3,3,3,3,
                3,3,3,3,
                3,3,6,3
            )
        );

        // WW
        expect(
            Tensor44I(
                1,1,1,1,
                1,1,1,1,
                1,1,1,1,
                1,1,1,2
            ) * 3 ==  Tensor44I(
                3,3,3,3,
                3,3,3,3,
                3,3,3,3,
                3,3,3,6
            )
        );
    };
    
    "Divide-int"_test = []{
        // uniform
        expect(
            Tensor44I(
                3,3,3,3,
                3,3,3,3,
                3,3,3,3,
                3,3,3,3
            ) / 3 ==  Tensor44I(
                1,1,1,1,
                1,1,1,1,
                1,1,1,1,
                1,1,1,1
            )
        );

        // XX
        expect(
            Tensor44I(
                6,3,3,3,
                3,3,3,3,
                3,3,3,3,
                3,3,3,3
            ) / 3 ==  Tensor44I(
                2,1,1,1,
                1,1,1,1,
                1,1,1,1,
                1,1,1,1
            )
        );

        // XY
        expect(
            Tensor44I(
                3,6,3,3,
                3,3,3,3,
                3,3,3,3,
                3,3,3,3
            ) / 3 ==  Tensor44I(
                1,2,1,1,
                1,1,1,1,
                1,1,1,1,
                1,1,1,1
            )
        );

        // XZ
        expect(
            Tensor44I(
                3,3,6,3,
                3,3,3,3,
                3,3,3,3,
                3,3,3,3
            ) / 3 ==  Tensor44I(
                1,1,2,1,
                1,1,1,1,
                1,1,1,1,
                1,1,1,1
            )
        );

        // XW
        expect(
            Tensor44I(
                3,3,3,6,
                3,3,3,3,
                3,3,3,3,
                3,3,3,3
            ) / 3 ==  Tensor44I(
                1,1,1,2,
                1,1,1,1,
                1,1,1,1,
                1,1,1,1
            )
        );


        // YX
        expect(
            Tensor44I(
                3,3,3,3,
                6,3,3,3,
                3,3,3,3,
                3,3,3,3
            ) / 3 ==  Tensor44I(
                1,1,1,1,
                2,1,1,1,
                1,1,1,1,
                1,1,1,1
            )
        );

        // YY
        expect(
            Tensor44I(
                3,3,3,3,
                3,6,3,3,
                3,3,3,3,
                3,3,3,3
            ) / 3 ==  Tensor44I(
                1,1,1,1,
                1,2,1,1,
                1,1,1,1,
                1,1,1,1
            )
        );

        // YZ
        expect(
            Tensor44I(
                3,3,3,3,
                3,3,6,3,
                3,3,3,3,
                3,3,3,3
            ) / 3 ==  Tensor44I(
                1,1,1,1,
                1,1,2,1,
                1,1,1,1,
                1,1,1,1
            )
        );

        // YW
        expect(
            Tensor44I(
                3,3,3,3,
                3,3,3,6,
                3,3,3,3,
                3,3,3,3
            ) / 3 ==  Tensor44I(
                1,1,1,1,
                1,1,1,2,
                1,1,1,1,
                1,1,1,1
            )
        );


        // ZX
        expect(
            Tensor44I(
                3,3,3,3,
                3,3,3,3,
                6,3,3,3,
                3,3,3,3
            ) / 3 ==  Tensor44I(
                1,1,1,1,
                1,1,1,1,
                2,1,1,1,
                1,1,1,1
            )
        );

        // ZY
        expect(
            Tensor44I(
                3,3,3,3,
                3,3,3,3,
                3,6,3,3,
                3,3,3,3
            ) / 3 ==  Tensor44I(
                1,1,1,1,
                1,1,1,1,
                1,2,1,1,
                1,1,1,1
            )
        );

        // ZZ
        expect(
            Tensor44I(
                3,3,3,3,
                3,3,3,3,
                3,3,6,3,
                3,3,3,3
            ) / 3 ==  Tensor44I(
                1,1,1,1,
                1,1,1,1,
                1,1,2,1,
                1,1,1,1
            )
        );

        // ZW
        expect(
            Tensor44I(
                3,3,3,3,
                3,3,3,3,
                3,3,3,6,
                3,3,3,3
            ) / 3 ==  Tensor44I(
                1,1,1,1,
                1,1,1,1,
                1,1,1,2,
                1,1,1,1
            )
        );


        // WX
        expect(
            Tensor44I(
                3,3,3,3,
                3,3,3,3,
                3,3,3,3,
                6,3,3,3
            ) / 3 ==  Tensor44I(
                1,1,1,1,
                1,1,1,1,
                1,1,1,1,
                2,1,1,1
            )
        );

        // WY
        expect(
            Tensor44I(
                3,3,3,3,
                3,3,3,3,
                3,3,3,3,
                3,6,3,3
            ) / 3 ==  Tensor44I(
                1,1,1,1,
                1,1,1,1,
                1,1,1,1,
                1,2,1,1
            )
        );

        // WZ
        expect(
            Tensor44I(
                3,3,3,3,
                3,3,3,3,
                3,3,3,3,
                3,3,6,3
            ) / 3 ==  Tensor44I(
                1,1,1,1,
                1,1,1,1,
                1,1,1,1,
                1,1,2,1
            )
        );

        // WW
        expect(
            Tensor44I(
                3,3,3,3,
                3,3,3,3,
                3,3,3,3,
                3,3,3,6
            ) / 3 ==  Tensor44I(
                1,1,1,1,
                1,1,1,1,
                1,1,1,1,
                1,1,1,2
            )
        );

    };

    return ut::cfg<>.run();
};

