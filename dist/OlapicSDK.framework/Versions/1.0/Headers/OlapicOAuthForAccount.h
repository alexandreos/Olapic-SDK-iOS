//
//  OlapicOAuthForAccount.h
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

#import "OlapicOAuthMethod.h"
/**
 *  The OAuth subclass to work with username and password
 */
@interface OlapicOAuthForAccount : OlapicOAuthMethod{
    /**
     *  The username and password for the connection
     */
    NSMutableString *username,*password;
    
}
/**
 *  The username and password for the connection
 */
@property (nonatomic,strong) NSMutableString *username,*password;
/**
 *  Class constructor
 *
 *  @param user The username
 *  @param pass The password
 *
 *  @return An instance of this class
 *  @since  v1.0
 */
-(id)initWithUsername:(NSString *)user andPassword:(NSString *)pass;
/**
 *  Change username and password. This can be sued
 *  after a failed connection
 *
 *  @param user The username
 *  @param pass The password
 *
 *  @since v1.0
 */
-(void)changeUsername:(NSString *)user andPassword:(NSString *)pass;

@end
