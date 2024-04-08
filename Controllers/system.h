#ifndef SYSTEM_H
#define SYSTEM_H

#include <QObject>

class System : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool nextClicked READ nextClicked WRITE setNextClicked NOTIFY nextClickedChanged)
    Q_PROPERTY(bool previousClicked READ previousClicked WRITE setPreviousClicked NOTIFY previousClickedChanged)
    Q_PROPERTY(bool playPause READ playPause WRITE setPlayPause NOTIFY playPauseChanged)
    Q_PROPERTY(bool playPausing READ playPausing WRITE setPlayPausing NOTIFY playPausingChanged)
    Q_PROPERTY(bool muted READ muted WRITE setMuted NOTIFY mutedChanged)
    Q_PROPERTY(double currentVolume READ currentVolume WRITE setCurrentVolume NOTIFY currentVolumeChanged)
    Q_PROPERTY(QString currentPage READ currentPage WRITE setCurrentPage NOTIFY currentPageChanged FINAL)

public:
    explicit System(QObject *parent = nullptr);
    bool nextClicked() const;
    bool previousClicked() const;
    bool playPause() const;
    bool playPausing() const;
    bool muted() const;
    double currentVolume() const;
    QString currentPage() const;

public slots:
    void setPlayPausing(bool newPlayPausing);
    void setPlayPause(bool newPlayPause);
    void setPreviousClicked(bool newPreviousClicked);
    void setNextClicked(bool newNextClicked);
    void setMuted(bool newMuted);
    void setCurrentVolume(int newCurrentVolume);
    void setCurrentPage(const QString &newCurrentPage);

signals:
    void nextClickedChanged();
    void previousClickedChanged();
    void playPauseChanged();
    void playPausingChanged();

    void mutedChanged();

    void currentVolumeChanged();

    void currentPageChanged();

private:
    bool m_nextClicked;
    bool m_previousClicked;
    bool m_playPause;
    bool m_playPausing;
    bool m_muted;
    double m_currentVolume;
    QString m_currentPage;
};

#endif // SYSTEM_H
