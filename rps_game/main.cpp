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

#include "gameengine.h"

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

const std::string cArgKeyLevel = "--level";
const std::string cArgKeyVersion = "--version";

const std::string cLevelStringEasy = "easy";
const std::string cLevelStringNormal = "normal";
const std::string cLevelStringHard = "hard";

const std::string cVersionString = "1.0";

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

void Play(Level level)
{
    GameEngine gameEngine;
    std::string enteredString;
    std::string gameBehaviour;

    while("0" != gameBehaviour)
    {
        std::cout << std::endl;
        std::cout << "Enter your shape (Rock|Paper|Scissors)" << std::endl;
        std::cin >> enteredString;

        for(auto c : enteredString)
        {
            tolower(c);
        }

        bool existShape = false;
        existShape =  gameEngine.UserShapeChoose(enteredString);

        if(existShape)
        {
            std::string programShape = gameEngine.ProgramShapeChoose(level);
            std::cout << programShape << std::endl;

            int gameResult = gameEngine.GameResult();
            if(1 == gameResult)
            {
                std::cout << "Congritulations!" << std::endl;
            }
            if(2 == gameResult)
            {
                std::cout << "You are looser :(" << std::endl;
            }
            if(0 == gameResult)
            {
                std::cout << "Drawn" << std::endl;
            }
        }
        else
        {
            std::cout << "Incorrect shape name" << std::endl;
        }

        gameBehaviour = "";

        while(("0" != gameBehaviour)&&("1" != gameBehaviour))
        {
            std::cout << "Enter [1] - to play new game, [0] - to exit" << std::endl;
            std::cin >> gameBehaviour;
        }
    }

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
    int keyVersionPosition = -1;
    keyVersionPosition = findArgPosition(argc, argv, cArgKeyVersion);

    if (keyVersionPosition != -1)
    {
        std::string programName = getFilename(argv[0], "\\");
        showInfo(programName, cVersionString);

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
    Play(level);

    return 0;
}


