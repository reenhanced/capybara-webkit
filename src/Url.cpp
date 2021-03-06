#include "Url.h"
#include "WebPage.h"

Url::Url(WebPage *page, QStringList &arguments, QObject *parent) : Command(page, arguments, parent) {
}

void Url::start() {
  QUrl humanUrl = page()->currentFrame()->url();
  QByteArray encodedBytes = humanUrl.toEncoded();
  QString urlString = QString(encodedBytes);
  emit finished(new Response(true, urlString));
}

