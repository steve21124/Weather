//
//  FindNearbyPlace.h
//  Weather
//
//  Created by Eugene Scherba on 11/10/11.
//  Copyright (c) 2011 Boston University. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol FindNearbyPlaceDelegate;

@class WeatherAppDelegate;

@interface FindNearbyPlace : NSObject {
    WeatherAppDelegate *appDelegate;
    NSMutableData *responseData;
    NSURL *theURL;
    
    id<FindNearbyPlaceDelegate> delegate;
}

-(void)queryServiceWithCoord:(CLLocationCoordinate2D)coord;

@property (nonatomic, assign) id<FindNearbyPlaceDelegate> delegate;
@end

@protocol FindNearbyPlaceDelegate
-(void)findNearbyPlaceDidFinish:(NSDictionary*)dict;
@end