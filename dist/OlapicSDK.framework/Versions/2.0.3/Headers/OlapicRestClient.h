//
//  OlapicRestClient.h
//  OlapicSDKFramework
//  https://github.com/Olapic/Olapic-SDK-iOS
//
//  Created by The Olapic Team on 4/17/14.
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
@class OlapicAFHTTPRequestOperationManager;
/**
 *  The object in charge of connecting with the API
 */
@interface OlapicRestClient : NSObject
/**-----------------------------------------------------------------------------
 * @name Detect Embedded Entities
 * -----------------------------------------------------------------------------
 */
/**
 *  Set the Rest client to detect or not embedded entities
 *  on the API requests.
 *
 *  @param detect Whether it should detect the entities or not.
 */
-(void)detectEmbeddedEntities:(BOOL)detect;
/**
 *  Check if the Rest client is detecting embedded entities
 *  on the API requests.
 *
 *  @return If the flag is ON or OFF.
 */
-(BOOL)detectEmbeddedEntities;
/**
 *  Set a RegEx pattern that will be used to evaluate an API
 *  request URL and see if it should detect embedded entities
 *  on the response or not.
 *
 *  Example:
 *
 *  ```
 *  [[[OlapicSDK sharedOlapicSDK] rest]
 *  setEndpointPatternForEmbeddedEntitiesDetection:@"\\/(media|stream|users)\\/([0-9]+|recent)(?:\\?|)"];
 *  ```
 *
 *  @param endpoint A RegEx pattern for the URL.
 */
-(void)setEndpointPatternForEmbeddedEntitiesDetection:(NSString *)endpoint;
/**
 *  Get the RegEx pattern for API request URL.
 *
 *  @return A RegEx pattern.
 */
-(NSString *)getEndpointPatternForEmbeddedEntitiesDetection;
/**
 *  Set a list of names for entities that should be detected
 *  on an API response.
 *
 *  Example:
 *
 *  ```
 *  NSArray *entities = [[NSArray alloc] initWithObjects:@"streams:all", @"categories:all", nil];
 *  [[[OlapicSDK sharedOlapicSDK] rest] setEntitiesToDetect:entities];
 *  ```
 *
 *  @param properties A list of entities names.
 */
-(void)setEntitiesToDetect:(NSArray *)properties;
/**
 *  Add a single entity name to the list of entities that
 *  should be detected on an API response.
 *
 *  Example:
 *
 *  ```
 *  [[[OlapicSDK sharedOlapicSDK] rest] addEntityToDetect:@"streams:all"];
 *  ```
 *
 *  @param entity The name of the entity.
 */
-(void)addEntityToDetect:(NSString *)entity;
/**
 *  Get the list of names for entities that should be detected
 *  on an API response.
 *
 *  @return A list of entities names.
 */
-(NSArray *)getEntitiesToDetect;
/**
 *  Set a dictionary with specific RegEx patterns for entities names,
 *  so, even if the main pattern matches, you can use this as an extra
 *  check for the entity.
 *
 *  Example:
 *
 *  ```
 *  NSMutableDictionary *patterns = [[NSMutableDictionary alloc] init];
 *  [patterns setValue:@"\\/(media|stream|users)\\/([0-9]+|recent)(?:\\?|)" forKey:@"streams:all"];
 *  [patterns setValue:@"\\/media\\/([0-9]+)" forKey:@"media"];
 *  [[[OlapicSDK sharedOlapicSDK] rest] setEntitiesToDetectPerEndpointPattern:patterns];
 *  ```
 *
 *  @param patterns A dicitionary where the keys are entities names and the values RegEx patterns for the URL.
 */
-(void)setEntitiesToDetectPerEndpointPattern:(NSDictionary *)patterns;
/**
 *  Set a single entity to be detected only when the given RegEx pattern
 *  matches the API request URL.
 *
 *  Example:
 *
 *  ```
 *  [[[OlapicSDK sharedOlapicSDK] rest] setEntityToDetect:@"media" forEndpointPattern:@"\\/media\\/([0-9]+)"];
 *  ```
 *
 *  @param entity  The entity name.
 *  @param pattern The RegEx pattern to match.
 */
-(void)setEntityToDetect:(NSString *)entity forEndpointPattern:(NSString *)pattern;
/**
 *  Get the dictionary with the specific URL RegEx patterns for entities.
 *
 *  @return A dicitionary where the keys are entities names and the values RegEx patterns for the URL.
 */
-(NSDictionary *)getEntitiesToDetectPerEndpointPattern;
/**
 *  In case the Pre Cache (the place where the detected entities are stored) has an entry for
 *  a request that you already obtained or you don't need anymore, you can use this method
 *  to remove the entry.
 *
 *  ```
 *  [[[OlapicSDK sharedOlapicSDK] rest] usePreCacheForURL:@"https://api.olapic.com/media/42"];
 *  ```
 *
 *  @param URL The API request URL.
 *
 *  @return Whether the entry was 'used' or not.
 */
-(BOOL)usePreCacheForURL:(NSString *)URL;
/**
 *  Get the list of detected entities by their URLs.
 *
 *  @return A dictionary with the entire contents of the Pre Cache.
 */
-(NSDictionary *)getPreCache;
/**
 *  Remove all entries from the Pre Cache.
 */
-(void)clearPreCache;

/**-----------------------------------------------------------------------------
 * @name GET
 * -----------------------------------------------------------------------------
 */
/**
 *  Make a GET request. In case the request fails, it
 *  will get a new OAuth token and try it again
 *
 *  Example:
 *
 *  ```
 *  [[[OlapicSDK sharedOlapicSDK] rest] get:@"//photorankapi-a.akamaihd.net/customers/{ID}/media/recent/"
 *  									parameters:nil
 *  									onSuccess:^(id responseObject){
 *  										NSLog(@"Response: %@",responseObject);
 *  									}
 *  									onFailure:^(NSError *error){
 *  										NSLog(@"Error: %@",error.description);
 *  									}];
 *  ```
 *
 *  @param URL        The API URL
 *  @param parameters The parameters for the query string
 *  @param success    A callback block for when the connection is successfully done
 *  @param failure    A callback block for when the connection fails
 *  @since            v1.0
 */
-(void)get:(NSString *)URL parameters:(NSDictionary *)parameters onSuccess:(void (^)(id responseObject))success onFailure:(void (^)(NSError *error))failure;
/**
 *  Make a GET request with extra request headers. In case
 *  the request fails, it will get a new OAuth token and
 *  try it again
 *
 *  Example:
 *
 *  ```
 *  NSMutableDictionary *headers = [[NSMutableDictionary alloc] init];
 *  [headers setValue:@"Olapic" forKey:@"requestedBy"];
 *  [[[OlapicSDK sharedOlapicSDK] rest] get:@"//photorankapi-a.akamaihd.net/customers/{ID}/media/recent/"
 *  									parameters:nil
 *  									onSuccess:^(id responseObject){
 *  										NSLog(@"Response: %@",responseObject);
 *  									}
 *  									onFailure:^(NSError *error){
 *  										NSLog(@"Error: %@",error.description);
 *  									} extraHeaders:headers];
 *  ```
 *
 *  @param URL        The API URL
 *  @param parameters The parameters for the query string
 *  @param success    A callback block for when the connection is successfully done
 *  @param failure    A callback block for when the connection fails
 *  @param headers    Extra headers for the request
 *  @since            v1.0
 */
-(void)get:(NSString *)URL parameters:(NSDictionary *)parameters onSuccess:(void (^)(id responseObject))success onFailure:(void (^)(NSError *error))failure extraHeaders:(NSDictionary *)headers;
/**
 *  Make a GET request with extra request headers and set
 *  if it should try to reconnect with a new OAuth token
 *  if it fails. If reconnect is NO, it means that this
 *  is not a reconnection and it should try to do it again
 *
 *  Example:
 *
 *  ```
 *  NSMutableDictionary *headers = [[NSMutableDictionary alloc] init];
 *  [headers setValue:@"Olapic" forKey:@"requestedBy"];
 *  [[[OlapicSDK sharedOlapicSDK] rest] get:@"//photorankapi-a.akamaihd.net/customers/{ID}/media/recent/"
 *  									parameters:nil
 *  									onSuccess:^(id responseObject){
 *  										NSLog(@"Response: %@",responseObject);
 *  									}
 *  									onFailure:^(NSError *error){
 *  										NSLog(@"Error: %@",error.description);
 *  									} extraHeaders:headers reconnect:YES];
 *  ```
 *
 *  @param URL        The API URL
 *  @param parameters The parameters for the query string
 *  @param success    A callback block for when the connection is successfully done
 *  @param failure    A callback block for when the connection fails
 *  @param headers    Extra headers for the request
 *  @param reconnect  If the request is a reconnection. If YES, it won't try to connect in case of failure
 *  @since            v1.0
 */
-(void)get:(NSString *)URL parameters:(NSDictionary *)parameters onSuccess:(void (^)(id responseObject))success onFailure:(void (^)(NSError *error))failure extraHeaders:(NSDictionary *)headers reconnect:(BOOL)reconnect;
/**
 *  Make a GET request, but get the result on NSData format.
 *  This can be used to load an image
 *
 *  Example:
 *
 *  ```
 *  [[[OlapicSDK sharedOlapicSDK] rest] getData:@"//photorankapi-a.akamaihd.net/sample.png"
 *  									parameters:nil
 *  									onSuccess:^(id responseObject){
 *  										NSLog(@"Response: %@",responseObject);
 *  									}
 *  									onFailure:^(NSError *error){
 *  										NSLog(@"Error: %@",error.description);
 *  									}];
 *  ```
 *
 *  @param URL        The API URL
 *  @param parameters The parameters for the query string
 *  @param success    A callback block for when the connection is successfully done
 *  @param failure    A callback block for when the connection fails
 *  @since            v1.0
 */
-(void)getData:(NSString *)URL parameters:(NSDictionary *)parameters onSuccess:(void (^)(NSData *responseData))success onFailure:(void (^)(NSError *error))failure;
/**-----------------------------------------------------------------------------
 * @name POST
 * -----------------------------------------------------------------------------
 */
/**
 *  Make a POST Request. In case the request fails, it
 *  will get a new OAuth token and try it again
 *
 *  Example:
 *
 *  ```
 *  [[[OlapicSDK sharedOlapicSDK] rest] post:@"//photorankapi-a.akamaihd.net/post"
 *  									parameters:nil
 *  									data:postData
 *  									onSuccess:^(id responseObject){
 *  										NSLog(@"Response: %@",responseObject);
 *  									}
 *  									onFailure:^(NSError *error){
 *  										NSLog(@"Error: %@",error.description);
 *  									}];
 *  ```
 *
 *  @param URL        The API URL
 *  @param parameters The parameters for the query string
 *  @param data       A list of metadata information
 *  @param success    A callback block for when the connection is successfully done
 *  @param failure    A callback block for when the connection fails
 *  @since            v1.0
 */
-(void)post:(NSString *)URL parameters:(NSDictionary *)parameters data:(NSArray *)data onSuccess:(void (^)(id responseObject))success onFailure:(void (^)(NSError *error))failure;
/**
 *  Make a POST Request and track the connection progress. In case
 *  the request fails, it will get a new OAuth token and try it again
 *
 *  Example:
 *
 *  ```
 *  [[[OlapicSDK sharedOlapicSDK] rest] post:@"//photorankapi-a.akamaihd.net/post"
 *  									parameters:nil
 *  									data:postData
 *  									onSuccess:^(id responseObject){
 *  										NSLog(@"Response: %@",responseObject);
 *  									}
 *  									onFailure:^(NSError *error){
 *  										NSLog(@"Error: %@",error.description);
 *  									}
 *  									onProgress:^(float progress){
 *  										NSLog(@"Progress: %%@",(progress/100));
 *  									}];
 *  ```
 *
 *  @param URL        The API URL
 *  @param parameters The parameters for the query string
 *  @param data       A list of metadata information
 *  @param success    A callback block for when the connection is successfully done
 *  @param failure    A callback block for when the connection fails
 *  @param progress   A callback block that can be used to track the connection progress
 *  @since            v1.0
 */
-(void)post:(NSString *)URL parameters:(NSDictionary *)parameters data:(NSArray *)data onSuccess:(void (^)(id responseObject))success onFailure:(void (^)(NSError *error))failure onProgress:(void (^)(float progress))progress;
/**
 *  Make a POST Request, track the connection progress and
 *  set if it should try to reconnect with a new OAuth token
 *  if it fails. If reconnect is NO, it means that this is not
 *  a reconnection and it should try to do it again
 *
 *  Example:
 *
 *  ```
 *  [[[OlapicSDK sharedOlapicSDK] rest] post:@"//photorankapi-a.akamaihd.net/post"
 *  									parameters:nil
 *  									data:postData
 *  									onSuccess:^(id responseObject){
 *  										NSLog(@"Response: %@",responseObject);
 *  									}
 *  									onFailure:^(NSError *error){
 *  										NSLog(@"Error: %@",error.description);
 *  									}
 *  									onProgress:^(float progress){
 *  										NSLog(@"Progress: %%@",(progress/100));
 *  									}];
 *  ```
 *
 *  @param URL        The API URL
 *  @param parameters The parameters for the query string
 *  @param data       A list of metadata information
 *  @param success    A callback block for when the connection is successfully done
 *  @param failure    A callback block for when the connection fails
 *  @param progress   A callback block that can be used to track the connection progress
 *  @param reconnect  If the request is a reconnection. If YES, it won't try to connect in case of failure
 *  @since            v1.0
 */
-(void)post:(NSString *)URL parameters:(NSDictionary *)parameters data:(NSArray *)data onSuccess:(void (^)(id responseObject))success onFailure:(void (^)(NSError *error))failure onProgress:(void (^)(float progress))progress reconnect:(BOOL)reconnect;
/**
 *  Make a POST request using a JSON object as
 *  request payload. This is a generic method and
 *  it won't use the Olapic API OAuth parameters
 *
 *  Example:
 *
 *  ```
 *  NSMutableDictinoary *JSON = [[NSMutableDictionary alloc] init];
 *  [JSON setValue:@"value" forKey:@"key"];
 *  [[[OlapicSDK sharedOlapicSDK] rest] postJSON:@"//photorankapi-a.akamaihd.net/json"
 *  									withContent:JSON
 *  									onSuccess:^(id responseObject){
 *  										NSLog(@"Response: %@",responseObject);
 *  									}
 *  									onFailure:^(NSError *error){
 *  										NSLog(@"Error: %@",error.description);
 *  									}];
 *  ```
 *
 *  @param URL     The API URL
 *  @param content The object to be used as JSON
 *  @param success A callback block for when the connection is successfully done
 *  @param failure A callback block for when the connection fails
 *  @since v1.0
 */
-(void)postJSON:(NSString *)URL withContent:(NSDictionary *)content onSuccess:(void (^)(id responseObject))success onFailure:(void (^)(NSError *error))failure;
/**-----------------------------------------------------------------------------
 * @name LINK/UNLINK
 * -----------------------------------------------------------------------------
 */
/**
 *  Make a LINK request to the API. In case the request
 *  fails, it will get a new OAuth token and try it again
 *
 *  Example:
 *
 *  ```
 *  NSMutableDictionary *headers = [[NSMutableDictionary alloc] init];
 *  [headers setValue:@"<stream-url>; rel=relation" forKey:@"requestedBy"];
 *  [[[OlapicSDK sharedOlapicSDK] rest] link:@"//photorankapi-a.akamaihd.net/customers/{ID}/media/recent/"
 *  									withMethod:@"GET"
 *  									parameters:nil
 *  									onSuccess:^(id responseObject){
 *  										NSLog(@"Response: %@",responseObject);
 *  									}
 *  									onFailure:^(NSError *error){
 *  										NSLog(@"Error: %@",error.description);
 *  									} extraHeaders:headers reconnect:YES];
 *  ```
 *
 *  @param URL        The API URL
 *  @param parameters The parameters for the query string
 *  @param success    A callback block for when the connection is successfully done
 *  @param failure    A callback block for when the connection fails
 *  @param headers    Extra headers for the request
 *  @param reconnect  If the request is a reconnection. If YES, it won't try to connect in case of failure
 *  @since v1.0
 */
-(void)link:(NSString *)URL parameters:(NSDictionary *)parameters onSuccess:(void (^)(id responseObject))success onFailure:(void (^)(NSError *error))failure extraHeaders:(NSDictionary *)headers reconnect:(BOOL)reconnect;
/**
 *  Make a UNLINK request to the API. In case the request
 *  fails, it will get a new OAuth token and try it again
 *
 *  Example:
 *
 *  ```
 *  NSMutableDictionary *headers = [[NSMutableDictionary alloc] init];
 *  [headers setValue:@"<stream-url>; rel=relation" forKey:@"requestedBy"];
 *  [[[OlapicSDK sharedOlapicSDK] rest] unlink:@"//photorankapi-a.akamaihd.net/customers/{ID}/media/recent/"
 *  									withMethod:@"GET"
 *  									parameters:nil
 *  									onSuccess:^(id responseObject){
 *  										NSLog(@"Response: %@",responseObject);
 *  									}
 *  									onFailure:^(NSError *error){
 *  										NSLog(@"Error: %@",error.description);
 *  									} extraHeaders:headers reconnect:YES];
 *  ```
 *
 *  @param URL        The API URL
 *  @param parameters The parameters for the query string
 *  @param success    A callback block for when the connection is successfully done
 *  @param failure    A callback block for when the connection fails
 *  @param headers    Extra headers for the request
 *  @param reconnect  If the request is a reconnection. If YES, it won't try to connect in case of failure
 *  @since v1.0
 */
-(void)unlink:(NSString *)URL parameters:(NSDictionary *)parameters onSuccess:(void (^)(id responseObject))success onFailure:(void (^)(NSError *error))failure extraHeaders:(NSDictionary *)headers reconnect:(BOOL)reconnect;
/**-----------------------------------------------------------------------------
 * @name Base
 * -----------------------------------------------------------------------------
 */
/**
 *  Do a basic request to the API server using a custom
 *  connection method, query string parameters and extra
 *  request headers. You can also use the reconnect flag
 *  to indicate that this is not a reconnection and that
 *  in case of failing, it should try the request again
 *
 *  This method is used by get:..., link:... and unlink:...
 *
 *  Example:
 *
 *  ```
 *  NSMutableDictionary *headers = [[NSMutableDictionary alloc] init];
 *  [headers setValue:@"Olapic" forKey:@"requestedBy"];
 *  [[[OlapicSDK sharedOlapicSDK] rest] simpleRequest:@"//photorankapi-a.akamaihd.net/customers/{ID}/media/recent/"
 *  									withMethod:@"GET"
 *  									parameters:nil
 *  									onSuccess:^(id responseObject){
 *  										NSLog(@"Response: %@",responseObject);
 *  									}
 *  									onFailure:^(NSError *error){
 *  										NSLog(@"Error: %@",error.description);
 *  									} extraHeaders:headers reconnect:YES];
 *  ```
 *
 *  @param URL        The API URL
 *  @param method     The request method (For now, it only supports: GET, LINK and UNLINK)
 *  @param parameters Query string parameters
 *  @param success    A callback block for when the connection is successfully done
 *  @param failure    A callback block for when the connection fails
 *  @param headers    A dictionary with extra request headers
 *  @param reconnect  If the request is a reconnection. If YES, it won't try to connect in case of failure
 *  @since v1.0
 */

-(void)baseRequest:(NSString *)URL method:(NSString *)method parameters:(NSDictionary *)parameters onSuccess:(void (^)(id responseObject))success onFailure:(void (^)(NSError *error))failure headers:(NSDictionary *)headers reconnect:(BOOL)reconnect;
/**-----------------------------------------------------------------------------
 * @name Extras
 * -----------------------------------------------------------------------------
 */
/**
 *  Prepare a dictionary to be sent on a POST request
 *
 *  @param metadata The information to prepare
 *
 *  @return A list with the information ready
 *  @since  v1.0
 */
-(NSArray *)prepareMetadataForPOST:(NSDictionary *)metadata;
/**
 *  Validate an API response (it will check
 *  for a 200 status)
 *
 *  @param  request The API response
 *
 *  @return If the response status is 200
 *  @since  v1.0
 */
-(BOOL)isValid:(NSDictionary *)request;
/**
 *  Get the AFNetworking operation manager
 *
 *  @return A new instance of the operation manager
 */
-(OlapicAFHTTPRequestOperationManager *)getOperationManager;
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
/**
 *  Generate a NSError object using a invalid response
 *  from the API
 *
 *  @param response The API response
 *
 *  @return A NSError object with the response metadata as description
 *  @since  v1.0
 */
-(NSError *)getErrorFromResponseMetadata:(NSDictionary *)response;
/**
 *  Because the requests inside a bulk request batch don't go
 *  through this class, they don't have the default parameters
 *  required by the API, like version and such.
 *
 *  @return The default parameters
 *  @since  v1.0
 */
-(NSDictionary *)getDefaultParametersForBulkRequestsToTheAPI;
@end