//
//  OlapicMediaStatusHandler.h
//  OlapicSDKFramework
//  https://github.com/Olapic/Olapic-SDK-iOS
//
//  Created by The Olapic Team on 7/3/14.
//  Copyright (c) 2014 Olapic, Inc. All rights reserved.
//  https://olapic.com
//
//  The MIT License (MIT)
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy of
//  this software and associated documentation files (the "Software"), to deal in
//  the Software without restriction, including without limitation the rights to
//  use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
//  the Software, and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#import "OlapicHandler.h"
@class OlapicMediaStatus;
/**
 *  The object in charge of creating and managing the OlapicStatus objects
 */
@interface OlapicMediaStatusHandler : OlapicHandler
/**
 *  Get all the statuses
 *
 *  Example:
 *
 *  ```
 *  [[[OlapicSDK sharedOlapicSDK] statuses]   getStatuses:^(NSDictionary *response){
 *  											  NSLog(@"Statuses %@",response);
 *  										  }
 *  										  onFailure:^(NSError *error){
 *  											  NSLog(@"Error: %@",error.description);
 *  										  }];
 *  ```
 *
 *  @param success A callback block for when the statuses are successfully retrieved
 *  @param failure A callback block for when the SDK can't get the statuses
 *  @since v1.0
 */
-(void)getStatuses:(void (^)(NSDictionary *response))success onFailure:(void (^)(NSError *error))failure;
/**
 *  Generate a status entity with a given name. It will
 *  not be saved on the API, this is just a shortcut to
 *  avoid downloading all the statuses and then just filter
 *  the one you want.
 *
 *  @param name The name of your status
 *
 *  @return The new status
 */
-(OlapicMediaStatus *)createStatusFromString:(NSString *)name;

@end