//
//  OlapicOAuthMethod.h
//  OlapicSDKFramework
//  https://github.com/Olapic/Olapic-SDK-iOS
//
//  Created by The Olapic Team on 9/11/14.
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

@class OlapicAFOAuth2Client;
@class OlapicAFOAuthCredential;
@class KeychainItemWrapper;
/**
 *  The base interface for the OAuth connections.
 *  The subclass should be able to get, validate
 *  and manage the tokens
 */
@interface OlapicOAuthMethod : NSObject{
    /**
     *  The AFNetworking 'plugin' that makes the connections to the OAuth server
     */
    OlapicAFOAuth2Client * OAuthClient;
    /**
     *  The object in charge of saving the credentials on the Keychain
     */
    KeychainItemWrapper *keychain;
}
/**
 *  The AFNetworking 'plugin' that makes the connections to the OAuth server
 */
@property (nonatomic,strong) OlapicAFOAuth2Client * OAuthClient;
/**
 *  The object in charge of saving the credentials on the Keychain
 */
@property (nonatomic,strong) KeychainItemWrapper *keychain;
/**
 *  The SDK singleton will use this method to set
 *  the OAuth server URL
 *
 *  @param URL The OAuth server URL
 *  @since v1.0
 */
-(void)setOAuthURL:(NSString *)URL;
/**
 *  Get the OAuth server URL
 *
 *  @return The OAuth server URL
 *  @since  v1.0
 */
-(NSString *)getOAuthURL;
/**
 *  Get the device identifier saved
 *  on the app settings
 *
 *  @return The identifier
 *  @since  v1.0
 */
-(NSString *)getDeviceIdentifier;
/**
 *  Get the AFNetworking OAuth 'plugin' instance
 *
 *  @return The OAuth client
 *  @since  v1.0
 */
-(OlapicAFOAuth2Client *)getOAuthClient;
/**
 *  Get the Keychain object to save and read credentials
 *
 *  @return The Keychain object
 *  @since  v1.0
 */
-(KeychainItemWrapper *)getKeychain;
/**
 *  This is the method the subclass will use
 *  to create an instance of the AFNetworking
 *  'plugin' and do extra setup
 *  @since  v1.0
 */
-(void)setup;
/**
 *  This is the method the subclass will use to
 *  validate the existence and the expiration date
 *  of a token, before doing any request
 *
 *  @param success The callback method to be called after a valid token is retrieved/created
 *  @param failure The callback method to be called if the client has to connect to the server, and the connection fails
 *  @since v1.0
 */
-(void)validateRequest:(void (^)(NSString *token))success onFailure:(void (^)(NSError *error))failure;
/**
 *  Check if a saved token can be reused. If it
 *  returns true, it can be retrieved using
 *  getSavedToken
 *
 *  @return If the token can be reused or not
 *  @since  v1.0
 */
-(BOOL)canReuseToken;
/**
 *  Retrieve a saved token from the
 *  app settings
 *
 *  @return The saved token
 *  @since  v1.0
 */
-(NSString *)getSavedToken;
/**
 *  Restore the saved token scopes into
 *  this object
 *
 *  @since  v1.0
 */
-(void)restoreScopes;
/**
 *  Once connected, this method can be used to
 *  retrieve the list of scopes associated to
 *  the token
 *
 *  @return The list of scopes
 *  @since  v1.0
 */
-(NSArray *)getScopes;
/**
 *  An easy way to check if the connected token
 *  has a specific scope
 *
 *  @param scope The scope you want to verify
 *
 *  @return Whether the scope is preset or not
 *  @since  v1.0
 */
-(BOOL)hasScope:(NSString *)scope;
/**
 *  Save a set of credentials provided by the
 *  AFNetworking 'plugin'
 *
 *  @param credentials The credentials object
 *  @since v1.0
 */
-(void)saveCredentials:(OlapicAFOAuthCredential *)credentials;
/**
 *  The key used by the class to saved information
 *  into the app settings.
 *  The subclass should extend this method with its
 *  own key.
 *
 *  @return The key
 *  @since  v1.0
 */
-(NSString *)getSettingsKey;
/**
 *  Clear any information saved on the
 *  app settings
 *
 *  @since v1.0
 */
-(void)clearCache;

@end