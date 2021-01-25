#ifndef WINDOW_H
#define WINDOW_H

#include "cube.h"

#include <QOpenGLWindow>
#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include <QQuaternion>
#include <QVector2D>
#include <QTime>
#include <QTimer>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLDebugLogger>

class Cube;

class Window: public QOpenGLWindow, protected QOpenGLFunctions
{
	Q_OBJECT
public:
    explicit Window(QWindow *parent = 0);
    ~Window();
protected:

    void mousePressEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *e) Q_DECL_OVERRIDE;

	void initializeGL() Q_DECL_OVERRIDE;
	void paintGL() Q_DECL_OVERRIDE;
	void resizeGL(int w, int h) Q_DECL_OVERRIDE;

	void initShaders();
	void initTextures();
	void initMatrixs();
	void useLightShader();
	void useMaterialShader();
private slots:
	void processTimeout();
    void onDebugMessage(const QOpenGLDebugMessage &debugMessage);
private:

    void calcFPS();
    void updateFPS(qreal);
    void paintFPS();

private:
	QTimer timer;
	QOpenGLShaderProgram program;
	QOpenGLShader *materialV, *materialF;
    QOpenGLShader *lightF, *lightV;
    Cube			*cube;

	QOpenGLTexture *texture;

	QMatrix4x4 projection;
	QMatrix4x4 model;
    QMatrix4x4 view;

    QVector3D lightPos;
    QVector2D mousePressPosition;
    QVector3D rotationAxis;

    QVector3D lightColor;
    qreal angularSpeed;
    QQuaternion rotation;
    qreal fps;

    QOpenGLDebugLogger debugger;
};

#endif // WINDOW_H
