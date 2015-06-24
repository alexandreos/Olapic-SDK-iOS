//
//  OlapicBulkRequest.h
//  OlapicSDKFramework
//  https://github.com/Olapic/Olapic-SDK-iOS
//
//  Created by The Olapic Team on 7/8/14.
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

#import <Foundation/Foundation.h>

@class OlapicSDK;
/**
 *  Create and process bulk requests to the API
 */
@interface OlapicBulkRequest : NSObject
/**-----------------------------------------------------------------------------
 * @name Add URLs
 * -----------------------------------------------------------------------------
 */
/**
 *  Add a URL to the batch
 *
 *  @param URL The URL to be added
 *  @since v1.0
 */
-(void)addRequestToURL:(NSString *)URL;
/**
 *  Add a URL with extra query string
 *  parameters to the batch
 *
 *  @param URL        The URL to be added
 *  @param parameters The extra parameters
 *  @since v1.0
 */
-(void)addRequestToURL:(NSString *)URL withParameters:(NSDictionary *)parameters;
/**
 *  Add a URL to the batch, with extra
 *  query string parameters and extra
 *  request headers
 *
 *  @param URL        The URL to be added
 *  @param parameters The extra parameters
 *  @param headers    The extra request headers
 *  @since v1.0
 */
-(void)addRequestToURL:(NSString *)URL withParameters:(NSDictionary *)parameters requestHeaders:(NSDictionary *)headers;
/**
 *  Add a URL to the batch, with extra
 *  request headers and extra parameters
 *  for the query string or the body, depending
 *  on the selected method (@"POST" or @"GET")
 *
 *  @param URL        The URL to be added
 *  @param parameters The extra parameters
 *  @param headers    The extra request headers
 *  @param method     The request method (@"POST" or @"GET")
 */
-(void)addRequestToURL:(NSString *)URL withParameters:(NSDictionary *)parameters requestHeaders:(NSDictionary *)headers andMethod:(NSString *)method;
/**-----------------------------------------------------------------------------
 * @name Sending the requests
 * -----------------------------------------------------------------------------
 */
/**
 *  Start processing the batch with all
 *  the requests
 *
 *  @param success A callback block for when the requests are done
 *  @param failure A callback block for when the connection to the bulk server fails
 */
-(void)process:(void (^)(NSArray *responseObject))success onFailure:(void (^)(NSError *error))failure;
/**-----------------------------------------------------------------------------
 * @name Utils
 * -----------------------------------------------------------------------------
 */
/**
 *  Get the OlapicSDK reference
 *
 *  @return The OlapicSDK
 *  @since  v1.0
 */
-(OlapicSDK *)getSDK;
@end