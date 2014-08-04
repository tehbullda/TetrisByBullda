#include "stdafx.h"
#include "HighScoreList.h"
#include <fstream>
#include <iostream>

using namespace btetris;
using namespace std;

int HighScoreList::MAX_RECORDS = 10;
char HighScoreList::SEPARATOR = ',';

HighScoreList::HighScoreList()
:	m_highScoresPath("../data/scores/highscores.txt")
{

}

bool HighScoreList::Load()
{
	ifstream highScoresFile(m_highScoresPath);

	if (!highScoresFile.is_open())
	{
		cout << "failed to open file " << m_highScoresPath << endl;
		return false;
	}

	string line;
	while (getline(highScoresFile, line))
	{
		int separatorPos = line.find_last_of(SEPARATOR);
		
		if (separatorPos != std::string::npos)
		{
			string name(line.substr(0, separatorPos));
			string scoreStr(line.substr(separatorPos + 1, std::string::npos));

			std::string::size_type sz;
			int score = std::stoi(scoreStr, &sz);

			m_highScoreRecords.push_back(HighScoreRecord(score, name));
		}
	}

	highScoresFile.close();

	return true;
}

bool HighScoreList::Save() const
{
	ofstream highScoresFile;
	highScoresFile.open(m_highScoresPath, ios::trunc);

	if (!highScoresFile.is_open())
	{
		cout << "failed to open file " << m_highScoresPath << endl;
		return false;
	}

	std::list<HighScoreRecord>::const_iterator it;

	for (it = m_highScoreRecords.begin(); it != m_highScoreRecords.end(); ++it)
	{
		string name(it->GetName());
		string score(std::to_string(it->GetScore()));
		highScoresFile << name << SEPARATOR << score << endl;
	}

	highScoresFile.close();

	return true;
}

HighScoreRecord HighScoreList::GetHighScoreAt(int position) const
{
	if (position < 1 || position > (int)m_highScoreRecords.size())
	{
		// artificial record, this sould only happen when list is empty
		return HighScoreRecord(0, "");
	}

	std::list<HighScoreRecord>::const_iterator it = m_highScoreRecords.begin();

	for (int i = 1; i < position; ++i)
	{
		++it;
	}

	return *it;
}

int HighScoreList::CalculatePositionFor(int score) const
{
	std::list<HighScoreRecord>::const_iterator it;
	int placeInList = 1;

	for (it = m_highScoreRecords.begin(); it != m_highScoreRecords.end(); ++it)
	{
		const HighScoreRecord& current = (*it);

		if (score > current.GetScore())
		{
			break;
		}

		++placeInList;
	}

	return placeInList;
}

void HighScoreList::Put(const HighScoreRecord& record)
{
	const int placeInList = CalculatePositionFor(record.GetScore());
	const int numberOfRecords = (int)m_highScoreRecords.size();

	if (placeInList <= MAX_RECORDS)
	{
		if (numberOfRecords >= MAX_RECORDS)
		{
			m_highScoreRecords.pop_back();
		}

		m_highScoreRecords.push_back(record);
		m_highScoreRecords.sort();
		m_highScoreRecords.reverse();
	}
}

bool HighScoreList::IsHighScore(int score) const
{
	const int placeInList = CalculatePositionFor(score);
	return placeInList <= MAX_RECORDS;
}
