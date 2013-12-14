//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************

//
// Scenario5.xaml.h
// Declaration of the Scenario5 class
//

#pragma once

#include "pch.h"
#include "Scenario5.g.h"
#include "MainPage.xaml.h"

namespace SDKSample
{
    namespace HttpClientSample
    {
        /// <summary>
        /// An empty page that can be used on its own or navigated to within a Frame.
        /// </summary>
        [ Windows::Foundation::Metadata::WebHostHidden ]
        public ref class Scenario5 sealed
        {
        public:
            Scenario5();
    
        protected:
            virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
    
        private:
            MainPage^ rootPage;
            Windows::Web::Http::HttpClient^ httpClient;
            concurrency::cancellation_token_source cancellationTokenSource;
            void Start_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
            void Cancel_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
            Concurrency::task<Windows::Storage::Streams::IRandomAccessStream^> GenerateSampleStreamAsync(
                unsigned int size,
                Concurrency::cancellation_token token);
        };
    }
}