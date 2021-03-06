#include "Reset.h"
#include "WebPage.h"
#include "NetworkAccessManager.h"

Reset::Reset(WebPage *page, QObject *parent) : Command(page, parent) {
}

void Reset::start(QStringList &arguments) {
  Q_UNUSED(arguments);

  page()->triggerAction(QWebPage::Stop);
  page()->currentFrame()->setHtml("<html><body></body></html>");
  page()->networkAccessManager()->setCookieJar(new QNetworkCookieJar());
  page()->setNetworkAccessManager(new NetworkAccessManager());
  page()->setUserAgent(NULL);
  emit finished(new Response(true));
}

