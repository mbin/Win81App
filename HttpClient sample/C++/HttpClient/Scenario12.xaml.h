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
// Scenario12.xaml.h
// Declaration of the Scenario12 class
//

#pragma once

#include "pch.h"
#include "Scenario12.g.h"
#include "MainPage.xaml.h"

namespace SDKSample
{
    namespace HttpClientSample
    {
        /// <summary>
        /// An empty page that can be used on its own or navigated to within a Frame.
        /// </summary>
        [ Windows::Foundation::Metadata::WebHostHidden ]
        public ref class Scenario12 sealed
        {
        public:
            Scenario12();

        protected:
            virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
            virtual void OnNavigatedFrom(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;

        private:
            MainPage^ rootPage;
            Windows::Foundation::EventRegistrationToken commandsRequestedEventRegistrationToken;
            Windows::Foundation::EventRegistrationToken windowActivatedEventRegistrationToken;
            Windows::UI::Xaml::Controls::Primitives::Popup^ settingsPopup;
            HttpFilters::HttpMeteredConnectionFilter^ meteredConnectionFilter;
            Windows::Web::Http::HttpClient^ httpClient;
            concurrency::cancellation_token_source cancellationTokenSource;

            void OnCommandsRequested(
                Windows::UI::ApplicationSettings::SettingsPane^ settingsPane,
                Windows::UI::ApplicationSettings::SettingsPaneCommandsRequestedEventArgs^ eventArgs);
            void OnSettingsCommand(Windows::UI::Popups::IUICommand^ command);
            void OnWindowActivated(Platform::Object^ sender, Windows::UI::Core::WindowActivatedEventArgs^ e);
            void OnPopupClosed(Platform::Object^ sender, Platform::Object^ args);
            void Start_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
            void Cancel_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        };
    }
}