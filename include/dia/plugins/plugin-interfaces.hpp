#pragma once
#ifndef   DIA_PLUGINS_PLUGIN_INTERFACES_HPP
#define   DIA_PLUGINS_PLUGIN_INTERFACES_HPP


// standard library
#include <list>
#include <string_view>


namespace dia::plugins::details
{
	using std::list;
	using std::string_view;


	// plugin base class
	class IPlugin
	{
	public: // creation and destruction of objects
		explicit IPlugin() noexcept = default;
		virtual ~IPlugin() noexcept = default;

	public: // basic information about the plugin
		virtual auto name() const noexcept -> string_view = 0;
		virtual auto vendor() const noexcept -> string_view = 0;
		virtual auto version() const noexcept -> string_view = 0;
		virtual auto license() const noexcept -> string_view = 0;
		virtual auto description() const noexcept -> string_view = 0;
		virtual auto url() const noexcept -> string_view = 0;

	public:
		virtual auto error_string() const noexcept -> string_view = 0;
	};

	class ILangPlugin: public IPlugin
	{
	public: // creation and destruction of objects
		explicit ILangPlugin() noexcept = default;
		virtual ~ILangPlugin() noexcept = default;

	public: // convert text into language representation
		virtual void parse(string_view text) noexcept = 0;
	};

	class IRendPlugin: public IPlugin
	{
	public: // creation and destruction of objects
		explicit IRendPlugin() noexcept = default;
		virtual ~IRendPlugin() noexcept = default;

	public: // link language and render plugins
		virtual auto bind(list<ILangPlugin*> const& langs) noexcept -> bool = 0;
		virtual auto get_langs() const noexcept -> list<ILangPlugin*> const& = 0;

	public: // show the language representation
		virtual void display(ILangPlugin* lang) noexcept = 0;
	};

	// active language and render class
	class IPluginPair
	{
	public: // creation and destruction of objects
		explicit IPluginPair() noexcept = default;
		virtual ~IPluginPair() noexcept = default;

	public:
		virtual void set_lang(ILangPlugin* lang) noexcept = 0;
		virtual auto lang() const noexcept -> ILangPlugin* = 0;

		virtual void set_rend(IRendPlugin* rend) noexcept = 0;
		virtual auto rend() const noexcept -> IRendPlugin* = 0;
	};
}

namespace dia::plugins
{
	using details::IPlugin;
	using details::ILangPlugin;
	using details::IRendPlugin;

	using details::IPluginPair;
}


#endif // DIA_PLUGINS_PLUGIN_INTERFACES_HPP