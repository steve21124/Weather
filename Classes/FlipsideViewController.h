//
// FlipsideViewController.h
// Weather
//
// Created by Eugene Scherba on 1/11/11.
// Copyright 2011 Boston University. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RSAddGeo.h"

@protocol FlipsideViewControllerDelegate;

@class WeatherAppDelegate;

@interface FlipsideViewController : UIViewController <RSAddGeoDelegate, UITableViewDelegate, UITableViewDataSource> {
    // ivar is autogenerated when the corresponding @property is specified
    //id <FlipsideViewControllerDelegate> delegate;
    WeatherAppDelegate *appDelegate;
    RSAddGeo *geoAddController;

    // for querying Google Places API
    NSURL *theURL;
    NSURLConnection *apiConnection;
    NSMutableData *responseData;
    NSMutableDictionary *modelDict;
    
    UISwitch *switchView;
    UISegmentedControl *segmentedControl;
    
    NSString *_requestedLocalityId;
    IBOutlet UITableView *_tableView;
}

// don't retain delegates
@property (nonatomic, assign) id <FlipsideViewControllerDelegate> delegate;
@property (nonatomic, retain) NSMutableDictionary *modelDict;

- (IBAction)addCityTouchDown;
- (IBAction)done:(id)sender;

@end

// A delegate of FlipsideViewController must implement the following protocol:
@protocol FlipsideViewControllerDelegate
- (void)insertViewFromIndex:(NSUInteger)fromIndex toIndex:(NSUInteger)toIndex;
- (void)flipsideViewControllerDidFinish:(FlipsideViewController *)controller;
- (void)addPageWithLocality:(RSLocality*)locality;
- (void)removePage:(NSInteger)index;
- (void)saveSettings;
- (void)locationSwitchSetTo:(BOOL)newState;
- (NSUInteger)permanentLocalityCount;
- (RSLocality*)getPermanentLocalityByRow:(NSUInteger)row;

@property (nonatomic, assign) BOOL trackLocation;
@property (nonatomic, retain) NSMutableArray *modelArray;
@end

