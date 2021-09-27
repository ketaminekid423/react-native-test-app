//
// Copyright (c) Microsoft Corporation
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.
//

#pragma once

#include <functional>
#include <optional>
#include <string>
#include <vector>

#include <winrt/Microsoft.ReactNative.h>
#include <winrt/Windows.Foundation.h>

#include <ReactContext.h>

namespace ReactTestApp
{
    extern std::vector<std::wstring> const JSBundleNames;

    enum class JSBundleSource {
        DevServer,
        Embedded,
    };

    using OnComponentsRegistered = std::function<void(std::vector<std::string> const &)>;

    class ReactInstance
    {
    public:
        ReactInstance();

        auto const &ReactHost() const
        {
            return reactNativeHost_;
        }

        bool LoadJSBundleFrom(JSBundleSource);
        void Reload();

        bool BreakOnFirstLine() const;
        void BreakOnFirstLine(bool);

        bool IsFastRefreshAvailable() const
        {
            return source_ == JSBundleSource::DevServer;
        }

        bool IsWebDebuggerAvailable() const
        {
            return source_ == JSBundleSource::DevServer;
        }

        template <typename F>
        void SetComponentsRegisteredDelegate(F &&f)
        {
            onComponentsRegistered_ = std::forward<F>(f);
        }

        void ToggleElementInspector() const;

        bool UseCustomDeveloperMenu() const;

        bool UseDirectDebugger() const;
        void UseDirectDebugger(bool);

        bool UseFastRefresh() const;
        void UseFastRefresh(bool);

        bool UseWebDebugger() const;
        void UseWebDebugger(bool);

    private:
        winrt::Microsoft::ReactNative::ReactNativeHost reactNativeHost_;
        winrt::Microsoft::ReactNative::ReactContext context_;
        JSBundleSource source_ = JSBundleSource::DevServer;
        OnComponentsRegistered onComponentsRegistered_;
    };

    std::optional<std::wstring> GetBundleName();
    winrt::Windows::Foundation::IAsyncOperation<bool> IsDevServerRunning();

}  // namespace ReactTestApp
