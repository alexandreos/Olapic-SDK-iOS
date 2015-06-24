Olapic iOS SDK v2.0
====================

Olapic's iOS SDK V2.0 contains code samples and documentation for leveraging the Olapic platform within an iOS app. The SDK makes it easier for iOS developers to build applications that can take advantage of Olapic's core offerings and capabilities.

To get started with the SDK, navigate to the `dist/` folder, which contains the `OlapicSDK.framework` file with the latest version of the SDK.

##What can you do with the Olapic SDK:

###Get Media

The iOS SDK offers 4 different ways to retrieve media: 

- Customer Level: All approved photos from your Olapic account

- Individual Media Level:  This will return a specific media

- Stream Level:  Returns all media from a specific stream

- Category Level: Returns media from a specific category
 
Olapic offers 4 different ways to sort retrieved media:

- Recent 
- Shuffled
- Photorank
- High Click Through Rate

###Upload Media

The SDK allows the capability of uploading UGC directly into your Olapic account. When media is uploaded, the API will return the user and media ID associated to that UGC.  

###Report Media

To best comply with copyright laws and regulations, Olapic provides an easy method to allow users to report media that is copyrighted or inappropriate. Our SDK provides easy access to this functionality so that you are in compliance with legal guidelines.  

###Manage Streams/Categories

Streams are an integral part of the Olapic platform and because of this we have made managing streams through the SDK simple. You'll be able to easily:

- Get a list of all Streams/Categories
- Get a specific Stream/Category

###Users

This feature will provide the tools to retrieve UGC from specific users and display that content. This is useful if you are interested in building profile pages for customers for whom you have Instagram photos within Olapic.  You would need to know your customer's Instagram username.  

##Requirements

- iOS 7.0+
- ARC
- An Olapic account and credentials

##Installation

###Authentication and Authorization:

The SDK uses OAuth to authenticate your account and provide access to our API. You'll need to open a ticket on our help desk in order to receive a **client ID** and a **secret key**

###Client Authentication

The first thing you need to do is import the `<OlapicSDK/OlapicSDK.h>` into your file, then you'll create an OAuth object for the authentication purposes and after that, you'll tell the SDK to connect to our API using that object. Once the connection is made, you'll be able to start using all the features from our SDK.

```obj-c
// Setup the OAuth client ID and secret key
NSString *clientID = @"YOUR_CLIENT_ID";
NSString *secretKey = @"YOUR_SECRET_KEY";
// Instantiate the OAuth handler
OlapicOAuthForSecretKey *oauth = [[OlapicOAuthForSecretKey alloc] initWithClientId:clientID andSecretKey:secretKey];
// Connect the SDK to our API using your OAuth method
[[OlapicSDK sharedOlapicSDK] connectWithOAuthMethod:oauth onSuccess:^(OlapicCustomerEntity *customer) {
    // Everything went fine, here's your information
    NSLog(@"Ready for %@", [customer get:@"name"]);
} onFailure:^(NSError *error) {
    // Error! Something happened!
    NSLog(@"Connection Error %@", error);
}];
```

*Note: Replace YOUR_CLIENT_ID and YOUR_SECRET_KEY with the information Olapic provided.*

###Get a list of media

Once the connection has been completed, the success callback will return the Customer entity, by using this entity you can get a list of media objects:

```
list = [[OlapicCustomerMediaList alloc] initForCustomer:customer delegate:self sort:SORTING_TYPE mediaPerPage:NUMBER_OF_MEDIAS_PER_PAGE];
```

The `list` variable should be an `OlapicCustomerMediaList` object, the `SORTING_TYPE` available are *[OlapicMediaListSortingTypeRecent, OlapicMediaListSortingTypeShuffled, OlapicMediaListSortingTypePhotorank, OlapicMediaListSortingTypeRated]*.

After this you need to use `[list startFetching];` to get all the media, this will execute the delegate methods with the information.

```
-(void)OlapicMediaList:(OlapicMediaList *)mediaList didLoadMedia:(NSArray *)media withLinks:(NSDictionary *)links;
-(void)OlapicMediaList:(OlapicMediaList *)mediaList didReceiveAnError:(NSError *)error
```

##Documentation

You can find the documentation on every class on [http://docs.photorank.me/ios/](http://docs.photorank.me/ios/).

##Start Making Amazing Apps

Once the SDK is installed and ready to go, start using it from any of your implementation files by adding the Olapic SDK header file. To import headers include the following line to your code:

`#import Ã¢â‚¬Å“OlapicSDK.hÃ¢â‚¬Â`

##License	

The Olapic SDK for iOS is available under the MIT license. See the LICENSE file for more info.