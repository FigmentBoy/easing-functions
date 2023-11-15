#include <cmath>
#include <map>

#include "easing.h"

#ifndef PI
#define PI 3.1415926545
#endif

float easeInSine( float t, float r ) {
	return sin( 1.5707963 * t );
}

float easeOutSine( float t, float r ) {
	return 1 + sin( 1.5707963 * (--t) );
}

float easeInOutSine( float t, float r ) {
	return 0.5 * (1 + sin( 3.1415926 * (t - 0.5) ) );
}

float easeInQuad( float t, float r ) {
    return t * t;
}

float easeOutQuad( float t, float r ) { 
    return t * (2 - t);
}

float easeInOutQuad( float t, float r ) {
    return t < 0.5 ? 2 * t * t : t * (4 - 2 * t) - 1;
}

float easeInCubic( float t, float r ) {
    return t * t * t;
}

float easeOutCubic( float t, float r ) {
    return 1 + (--t) * t * t;
}

float easeInOutCubic( float t, float r ) {
    return t < 0.5 ? 4 * t * t * t : 1 + (--t) * (2 * (--t)) * (2 * t);
}

float easeInQuart( float t, float r ) {
    t *= t;
    return t * t;
}

float easeOutQuart( float t, float r ) {
    t = (--t) * t;
    return 1 - t * t;
}

float easeInOutQuart( float t, float r ) {
    if( t < 0.5 ) {
        t *= t;
        return 8 * t * t;
    } else {
        t = (--t) * t;
        return 1 - 8 * t * t;
    }
}

float easeInQuint( float t, float r ) {
    float t2 = t * t;
    return t * t2 * t2;
}

float easeOutQuint( float t, float r ) {
    float t2 = (--t) * t;
    return 1 + t * t2 * t2;
}

float easeInOutQuint( float t, float r ) {
    float t2;
    if( t < 0.5 ) {
        t2 = t * t;
        return 16 * t * t2 * t2;
    } else {
        t2 = (--t) * t;
        return 1 + 16 * t * t2 * t2;
    }
}

float easeInExpo( float t, float r ) {
    return (pow( 2, 8 * t ) - 1) / 255;
}

float easeOutExpo( float t, float r ) {
    return 1 - pow( 2, -8 * t );
}

float easeInOutExpo( float t, float r ) {
    if( t < 0.5 ) {
        return (pow( 2, 16 * t ) - 1) / 510;
    } else {
        return 1 - 0.5 * pow( 2, -16 * (t - 0.5) );
    }
}

float easeInCirc( float t, float r ) {
    return 1 - sqrt( 1 - t );
}

float easeOutCirc( float t, float r ) {
    return sqrt( t );
}

float easeInOutCirc( float t, float r ) {
    if( t < 0.5 ) {
        return (1 - sqrt( 1 - 2 * t )) * 0.5;
    } else {
        return (1 + sqrt( 2 * t - 1 )) * 0.5;
    }
}

float easeInBack( float t, float r ) {
    return t * t * (2.70158 * t - 1.70158);
}

float easeOutBack( float t, float r ) {
    return 1 + (--t) * t * (2.70158 * t + 1.70158);
}

float easeInOutBack( float t, float r ) {
    if( t < 0.5 ) {
        return t * t * (7 * t - 2.5) * 2;
    } else {
        return 1 + (--t) * t * 2 * (7 * t + 2.5);
    }
}

float easeInElastic( float t, float r ) {
    float t2 = t * t;
    return t2 * t2 * sin( t * PI * 4.5 );
}

float easeOutElastic( float t, float r ) {
    float t2 = (t - 1) * (t - 1);
    return 1 - t2 * t2 * cos( t * PI * 4.5 );
}

float easeInOutElastic( float t, float r ) {
    float t2;
    if( t < 0.45 ) {
        t2 = t * t;
        return 8 * t2 * t2 * sin( t * PI * 9 );
    } else if( t < 0.55 ) {
        return 0.5 + 0.75 * sin( t * PI * 4 );
    } else {
        t2 = (t - 1) * (t - 1);
        return 1 - 8 * t2 * t2 * sin( t * PI * 9 );
    }
}

float easeInBounce( float t, float r ) {
    return pow( 2, 6 * (t - 1) ) * abs( sin( t * PI * 3.5 ) );
}

float easeOutBounce( float t, float r ) {
    return 1 - pow( 2, -6 * t ) * abs( cos( t * PI * 3.5 ) );
}

float easeInOutBounce( float t, float r ) {
    if( t < 0.5 ) {
        return 8 * pow( 2, 8 * (t - 1) ) * abs( sin( t * PI * 7 ) );
    } else {
        return 1 - 8 * pow( 2, -8 * t ) * abs( sin( t * PI * 7 ) );
    }
}

float easeIn( float t, float r ) {
    return pow( t, r );
}

float easeOut( float t, float r ) {
    return pow( t, 1 / r );
}

float easeInOut( float t, float r ) {
    float t2 = t * 2;
    if ( t2 < 1 ) {
        return 0.5 * pow( t2, r );
    } else {
        return (1 - 0.5 * pow( 2 - t2, r ));
    }
}

easingFunction getEasingFunction( easing_functions function )
{
	static std::map< easing_functions, easingFunction > easingFunctions;
	if( easingFunctions.empty() )
	{
		easingFunctions.insert( std::make_pair( EaseInSine, 	easeInSine ) );
		easingFunctions.insert( std::make_pair( EaseOutSine, 	easeOutSine ) );
		easingFunctions.insert( std::make_pair( EaseInOutSine, 	easeInOutSine ) );
		easingFunctions.insert( std::make_pair( EaseInQuad, 	easeInQuad ) );
		easingFunctions.insert( std::make_pair( EaseOutQuad, 	easeOutQuad ) );
		easingFunctions.insert( std::make_pair( EaseInOutQuad, 	easeInOutQuad ) );
		easingFunctions.insert( std::make_pair( EaseInCubic, 	easeInCubic ) );
		easingFunctions.insert( std::make_pair( EaseOutCubic, 	easeOutCubic ) );
		easingFunctions.insert( std::make_pair( EaseInOutCubic, easeInOutCubic ) );
		easingFunctions.insert( std::make_pair( EaseInQuart, 	easeInQuart ) );
		easingFunctions.insert( std::make_pair( EaseOutQuart, 	easeOutQuart ) );
		easingFunctions.insert( std::make_pair( EaseInOutQuart, easeInOutQuart) );
		easingFunctions.insert( std::make_pair( EaseInQuint, 	easeInQuint ) );
		easingFunctions.insert( std::make_pair( EaseOutQuint, 	easeOutQuint ) );
		easingFunctions.insert( std::make_pair( EaseInOutQuint, easeInOutQuint ) );
		easingFunctions.insert( std::make_pair( EaseInExpo, 	easeInExpo ) );
		easingFunctions.insert( std::make_pair( EaseOutExpo, 	easeOutExpo ) );
		easingFunctions.insert( std::make_pair( EaseInOutExpo,	easeInOutExpo ) );
		easingFunctions.insert( std::make_pair( EaseInCirc, 	easeInCirc ) );
		easingFunctions.insert( std::make_pair( EaseOutCirc, 	easeOutCirc ) );
		easingFunctions.insert( std::make_pair( EaseInOutCirc,	easeInOutCirc ) );
		easingFunctions.insert( std::make_pair( EaseInBack, 	easeInBack ) );
		easingFunctions.insert( std::make_pair( EaseOutBack, 	easeOutBack ) );
		easingFunctions.insert( std::make_pair( EaseInOutBack,	easeInOutBack ) );
		easingFunctions.insert( std::make_pair( EaseInElastic, 	easeInElastic ) );
		easingFunctions.insert( std::make_pair( EaseOutElastic, easeOutElastic ) );
		easingFunctions.insert( std::make_pair( EaseInOutElastic, easeInOutElastic ) );
		easingFunctions.insert( std::make_pair( EaseInBounce, 	easeInBounce ) );
		easingFunctions.insert( std::make_pair( EaseOutBounce, 	easeOutBounce ) );
		easingFunctions.insert( std::make_pair( EaseInOutBounce, easeInOutBounce ) );
        easingFunctions.insert( std::make_pair( EaseIn, 		easeIn ) );
        easingFunctions.insert( std::make_pair( EaseOut, 		easeOut ) );
        easingFunctions.insert( std::make_pair( EaseInOut, 		easeInOut ) );
	}

	auto it = easingFunctions.find( function );
	return it == easingFunctions.end() ? nullptr : it->second;
}
