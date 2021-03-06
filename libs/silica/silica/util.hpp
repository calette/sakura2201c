﻿// -*- mode:c++; coding:utf-8-ws -*-
//====================================================================
//! @file  util.hpp
//! @brief ユーティリティ
//!
//! @author (C) 2017, Niki.
//====================================================================
#ifndef SILICA_UTIL_HPP
#define SILICA_UTIL_HPP

#include "basis.h"

#include <codecvt>
#include <locale>

namespace si {

namespace util {

/*!
 * 文字列を真偽値に変換
 * @param s
 * @return true/false
 */
SILICA_INLINE bool to_b(const std::string &s)
{
	return !(s == "false" || s == "False" || s == "0");
}
SILICA_INLINE bool to_b(const std::wstring &s)
{
	return !(s == L"false" || s == L"False" || s == L"0");
}

/*!
 * wstring を string に変換
 */
SILICA_INLINE std::string to_bytes(const std::wstring &s)
{
	if (s.empty()) return "";
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> cv;
	return cv.to_bytes(s.c_str()); //wstring→string
}

/*!
 * string を wstring に変換
 */
SILICA_INLINE std::wstring from_bytes(const std::string &s)
{
	if (s.empty()) return L"";
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> cv;
	return cv.from_bytes(s.c_str()); //string→wstring
}

/*!
 * 文字列の左端から指定の文字を取り除く
 * @param s
 * @param c
 */
SILICA_INLINE std::tstring ltrim(const std::tstring &s, const TCHAR c)
{
	const TCHAR *p = s.c_str();
	while (*p == c) {
		p++;
	}
	return p;
}

/*!
 * 文字列の右端から指定の文字を取り除く
 * @param s
 * @param c
 */
SILICA_INLINE std::tstring rtrim(const std::tstring &s, const TCHAR c)
{
	const TCHAR *p = s.c_str() + s.length() - 1;
	while (*p == c) {
		p--;
	}
	return s.substr(0, ((size_t)p - (size_t)s.c_str()) / sizeof(TCHAR) + 1);
}

/*!
 * 文字列の置換
 */
SILICA_INLINE int replace(std::tstring &s, const std::tstring &from, const std::tstring &to)
{
	int repcnt = 0;
	std::tstring::size_type pos = s.find(from);
	while (pos != std::tstring::npos) {
		s.replace(pos, from.size(), to);
		repcnt++;
		pos = s.find(from, pos + to.size());
	}
	return repcnt;
}

} // namespace util

} // namespace si

#endif /* SILICA_UTIL_HPP */
