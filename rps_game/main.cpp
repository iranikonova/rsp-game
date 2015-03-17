/***************************************************************************
 * rps_game - Rock, Paper, Scissors Game                                   *
 *                                                                         *
 * Copyright (C) 2015  PLLUG.Community   (info@pllug.org.ua)               *
 *                                                                         *
 * This program is free software: you can redistribute it and/or modify    *
 * it under the terms of the GNU General Public License as published by    *
 * the Free Software Foundation, either version 3 of the License, or       *
 * (at your option) any later version.                                     *
 *                                                                         *
 * This program is distributed in the hope that it will be useful,         *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 * GNU General Public License for more details.                            *
 *                                                                         *
 * You should have received a copy of the GNU General Public License       *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.   *
 ***************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>

/*!
 * \brief The Level enum
 */
enum Level
{
    UNSPECIFIED_LEVEL = 0,
    EASY,
    NORMAL,
    HARD
};

/*!
 * \brief The Version enum
 */
enum Version
{
    UNSPECIFIED_VERSION = 0,
    _1_0,
    _1_1,
    _1_2
};

const std::string cArgKeyLevel = "--level";
const std::string cArgKeyVersion = "--version";

const std::string cLevelStringEasy = "easy";
const std::string cLevelStringNormal = "normal";
const std::string cLevelStringHard = "hard";

const std::string cVersionString1 = "1.0";
const std::string cVersionString2 = "1.1";
const std::string cVersionString3 = "1.2";

/*!
 * \brief showHelp
 */
void showHelp()
{
    std::cout << "Usage:" << std::endl;
    std::cout << "  rps_game [options]" << std::endl;
    std::cout << "      --level (EASY|NORMAL|HARD)" << std::endl;
    std::cout << "          specify game difficulty (argument is required)" << std::endl;
    std::cout << "      --version" << std::endl;
    std::cout << "          output programm version" << std::endl;
}

/*!
 * \brief showInfo
 */
void showInfo(std::string programName, std::string versionName)
{
    std::cout << "Program details:" << std::endl;
    std::cout << "  Name: " << programName << std::endl;
    std::cout << "  Version: " << versionName << std::endl;
    std::cout << "  Description: " << std::endl;
    std::cout << "      Rock-paper-scissors is a zero sum hand game" << std::endl;
    std::cout << "      usually played between two people/ players" << std::endl;
    std::cout << "      where each player simultaneously forms one of three shapes" << std::endl;
    std::cout << "      with an outstretched hand" << std::endl;
}

/*!
 * \brief parseLevel
 * \param levelString
 * \return
 */
Level parseLevel(std::string levelString)
{
    Level rLevel = UNSPECIFIED_LEVEL;

    std::transform(levelString.begin(), levelString.end(), levelString.begin(), ::tolower);

    if (cLevelStringEasy == levelString)
    {
        rLevel = EASY;
    }
    else if (cLevelStringNormal == levelString)
    {
        rLevel = NORMAL;
    }
    else if (cLevelStringHard == levelString)
    {
        rLevel = HARD;
    }

    return rLevel;
}

/*!
 * \brief parseVersion
 * \param versionString
 * \return
 */
Version parseVersion(std::string versionString)
{
    Version rVersion = UNSPECIFIED_VERSION;

    std::transform(versionString.begin(), versionString.end(), versionString.begin(), ::tolower);

    if (cVersionString1 == versionString)
    {
        rVersion = _1_0;
    }
    else if (cVersionString2 == versionString)
    {
        rVersion = _1_1;
    }
    else if (cVersionString3 == versionString)
    {
        rVersion = _1_2;
    }

    return rVersion;
}

/*!
 * \brief parseVersion
 * \param version
 * \return
 */
std::string parseVersion(Version version)
{
    std::string versionName;

    if (_1_0 == version)
    {
        versionName = cVersionString1;
    }
    else if (_1_1 == version)
    {
        versionName = cVersionString2;
    }
    else if (_1_2 == version)
    {
        versionName = cVersionString3;
    }

    return versionName;
}

/*!
 * \brief findArgPosition
 * \param argc
 * \param argv
 * \param argName
 * \return
 */
int findArgPosition(int argc, char* argv[], const std::string &argName)
{
    int rPosition = -1;

    for (int argIndex = 1; argIndex < argc; ++argIndex)
    {
        std::string nextArg = argv[argIndex];
        std::transform(nextArg.begin(), nextArg.end(), nextArg.begin(), ::tolower);

        if (argName == nextArg)
        {
            rPosition = argIndex;
        }
    }

    return rPosition;
}

/*!
 * \brief stringArg
 * \param argc
 * \param argv
 * \param argName
 * \return
 */
std::string stringArg(int argc, char* argv[], std::string argName)
{
    std::string result;

    int argIndex = findArgPosition(argc, argv, argName);

    if (-1 != argIndex)
    {
        if (argIndex + 1 < argc)
        {
            result = argv[argIndex + 1];
        }
    }

    return result;
}

/*!
 * \brief getFilename
 * \param separator
 * \return
 */
std::string getFilename(std::string path, char* separator)
{
    std::string filename;

    size_t beginPos = path.rfind(separator);
    size_t endPos = path.rfind('.');

    if((beginPos != std::string::npos) && (endPos != std::string::npos))
        filename = path.substr(beginPos + 1, endPos - beginPos - 1);

    return filename;
}

/*!
 * \brief main
 * \param argc
 * \param argv
 * \return
 */
int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        showHelp();
        return 1;
    }

    // Parse version
    Version version = UNSPECIFIED_VERSION;

    std::string versionStr = stringArg(argc, argv, cArgKeyVersion);
    if (!versionStr.empty())
    {
        version = parseVersion(versionStr);
    }

    if (UNSPECIFIED_VERSION != version)
    {
        std::string programName = getFilename(argv[0], "\\");
        std::string versionName = parseVersion(version);

        showInfo(programName, versionName);

        return 0;
    }

    // Parse level
    Level level = UNSPECIFIED_LEVEL;

    std::string levelStr = stringArg(argc, argv, cArgKeyLevel);
    if (!levelStr.empty())
    {
        level = parseLevel(levelStr);
    }

    if (UNSPECIFIED_LEVEL == level)
    {
        showHelp();
        return 1;
    }

    std::cout << level << std::endl;

    return 0;
}


