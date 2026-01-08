/**
 * @file 3433_Count_Mentions_Per_User.cpp
 * @author Rut Koticha
 * @date 2025-12-12
 */

#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>

const int g_MessageIndex = 0,
g_TimestampIndex = 1,
g_MentionsIndex = 2;

const std::string g_MessageType = "MESSAGE",
g_AllUsers = "ALL",
g_OnlineUsers = "HERE";

class Solution {
private: /* <---------- Methods ----------> */
  void MentionAllUsers(std::vector<int>& mentions)
  {
    for (int userMention : mentions)
      userMention++;
  }

  void UpdateStatus(std::queue<std::pair<int, int>> statusQueue, int timestamp)
  {
    while (!statusQueue.empty())
    {
      const std::pair<int, int> userStatus = statusQueue.front();
      const int statusTimestamp = userStatus.first;
      const int id = userStatus.second;

      if (statusTimestamp > timestamp)
        break;

      status.at(id) = true;
      statusQueue.pop();
    }

  }

  void MentionOnlineUsers(std::vector<int> mentions, std::vector<int> status)
  {
    for (int userMention : mentions)
      userMention++;
  }

  std::vector<int> TokenizeToIds(std::string string)
  {
    std::vector<int> ids;

    std::stringstream stream;
    std::string token;

    while (stream >> token)
    {
      ids.push_back(std::stoi(token.substr(2)));
    }

    return ids;
  }


  void MentionSelectedUsers(std::vector<int> mentions, std::string userMentions)
  {
    std::vector<int> ids = TokenizeToIds(userMentions);

    for (int id : ids)
    {
      mentions.at(id)++;
    }
  }

  void HandleMentions(std::vector<std::string> event,
    std::vector<int> mentions,
    std::vector<bool> status,
    std::queue<std::pair<int, int>>& statusQueue)
  {
    std::string ids = event.at(g_MentionsIndex);

    if (ids == g_AllUsers)
    {
      MentionAllUsers(mentions);
    }
    else if (ids == g_OnlineUsers)
    {
      for (int id = 0; id < numberOfUsers; id++)
      {
        if (status.at(id))
          mentions.at(id)++;
      }
    }
    else
    {
      MentionSelectedUsers(mentions, event.at(g_MentionsIndex));
    }

  }

  void HandleStatusChange(std::vector<std::string> event, std::queue<std::pair<int, int>>& statusQueue)
  {
    const int id = std::stoi(event.at(g_MentionsIndex));
    statusQueue.emplace(std::stoi(event.at(g_TimestampIndex)), id);
  }

public:
  std::vector<int> countMentions(int numberOfUsers, std::vector<std::vector<std::string>>& events)
  {
    std::vector<int> mentions(numberOfUsers, 0);
    std::vector<bool> status(numberOfUsers, true);
    std::queue<std::pair<int, int>> statusQueue;

    for (int i = 0; i < numberOfUsers; i++)
    {
      std::vector<std::string> event = events.at(i);

      if (event.at(g_MessageIndex) == g_MessageType)
      {
        HandleMentions(event, mentions, status, statusQueue);
      }
      else
      {
        HandleStatusChange(event, statusQueue);
      }
    }

    return mentions;
  }
};
