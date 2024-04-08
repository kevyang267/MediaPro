#include "system.h"

System::System(QObject *parent)
    : QObject{parent},
    m_nextClicked(false),
    m_previousClicked(false),
    m_playPause(true),
    m_muted(false),
    m_currentVolume(0.5),
    m_currentPage("playing")
{}

bool System::nextClicked() const
{
    return m_nextClicked;
}

void System::setNextClicked(bool newNextClicked)
{
    if (m_nextClicked == newNextClicked)
        return;
    m_nextClicked = newNextClicked;
    emit nextClickedChanged();
}

bool System::previousClicked() const
{
    return m_previousClicked;
}

void System::setPreviousClicked(bool newPreviousClicked)
{
    if (m_previousClicked == newPreviousClicked)
        return;
    m_previousClicked = newPreviousClicked;
    emit previousClickedChanged();
}

bool System::playPause() const
{
    return m_playPause;
}

void System::setPlayPause(bool newPlayPause)
{
    if (m_playPause == newPlayPause)
        return;
    m_playPause = newPlayPause;
    emit playPauseChanged();
}

bool System::playPausing() const
{
    return m_playPausing;
}

void System::setPlayPausing(bool newPlayPausing)
{
    if (m_playPausing == newPlayPausing)
        return;
    m_playPausing = newPlayPausing;
    emit playPausingChanged();
}

bool System::muted() const
{
    return m_muted;
}

void System::setMuted(bool newMuted)
{
    if (m_muted == newMuted)
        return;
    m_muted = newMuted;
    emit mutedChanged();
}

double System::currentVolume() const
{
    return m_currentVolume;
}

void System::setCurrentVolume(int newCurrentVolume)
{
    if (m_currentVolume == newCurrentVolume)
        return;
    m_currentVolume = newCurrentVolume;
    emit currentVolumeChanged();
}

QString System::currentPage() const
{
    return m_currentPage;
}

void System::setCurrentPage(const QString &newCurrentPage)
{
    if (m_currentPage == newCurrentPage)
        return;
    m_currentPage = newCurrentPage;
    emit currentPageChanged();
}

bool System::openFileDirectory() const
{
    return m_openFileDirectory;
}

void System::setopenFileDirectory(bool newOpenFileDirectory)
{
    if (m_openFileDirectory == newOpenFileDirectory)
        return;
    m_openFileDirectory = newOpenFileDirectory;

    emit openFileDirectoryChanged();
}
