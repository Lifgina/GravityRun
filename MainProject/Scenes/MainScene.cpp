//
// MainScene.cpp
//

#include "MainScene.h"

using namespace HE;

// initialize member variables.
MainScene::MainScene()
{

}

// rearrange UI to fit the size.
void MainScene::ResizeLayout()
{
	Scene::ResizeLayout();



}

// load resources.
void MainScene::Load()
{
	gameManager_.Load();
	gameOverView_.Load();
	bg_.Load();
	playerView_.Load();
	timerView_.Load();
	pillar_.Load();
	invincibleItemView_.Load();
	seManager_.Load();
	bgmManager_.Load();
	markerView_.Load();
	countdownView_.Load();
	for (int i = 0; i < floorData_.GetFloorCount(); i++)
	{
		floorView_[i].Load(floorData_.GetIsBreakable(i)); 
	}
	for (int i = 0; i < enemyData_.GetSilentEnemyCount(); i++)
	{
		silentEnemyView_[i].Load();
	}
	for (int i = 0; i < enemyData_.GetMoveEnemyCount(); i++)
	{
		moveEnemyView_[i].Load();
	}
	for (int i = 0; i < enemyData_.GetSuitonEnemyCount(); i++)
	{
		suitonEnemyView_[i].Load();
		suitonFusumaView_[i].Load(0,1);
		
	}
	for (int i = 0; i < enemyData_.GetKatonEnemyCount(); i++)
	{
		katonEnemyView_[i].Load();
		katonFusumaView_[i].Load(1, 0);
	}

	Scene::Load();
}

// initialize a variables.
void MainScene::Initialize()
{
	gameOverView_.Initialize(); // �Q�[���I�[�o�[�r���[�̏�����
	playerView_.Initialize(); // �v���C���[�̏�����
	timerView_.Initialize(); // �^�C�}�[�̏�����
	bg_.Initialize(); // �w�i�̏�����
	pillar_.Initialize(); // ���̏�����
	invincibleItemView_.Initialize(); // ���G�A�C�e���̏�����
	countdownView_.Initialize(); // �J�E���g�_�E���̏�����
	gameState_= 3; // �Q�[���I�[�o�[��Ԃ�������
	prevGameState_ = gameState_; // �O�̃Q�[����Ԃ�������
	isStartShowed_ = false; // �Q�[���J�n���\�����ꂽ���ǂ�����������
	gameManager_.Initialize(timeLimit_, floorData_.GetFloorCount(), enemyData_.GetSilentEnemyCount(), enemyData_.GetMoveEnemyCount(), enemyData_.GetSuitonEnemyCount(), enemyData_.GetSuitonAttackTimes(),enemyData_.GetKatonEnemyCount(),enemyData_.GetKatonAttackTimes());
	gameManager_.PlayerSetup(initialPlayerPosition_, leftEdge, rightEdge, isMovingToRightFirst_, isGravityUpwardFirst_, playerWidth_, playerHeight_);
	for (int i = 0; i <floorData_.GetFloorCount(); i++)
	{
		floorView_[i].Initialize(floorData_.GetFloorPosition(i), floorData_.GetFloorHeight(i), floorData_.GetFloorWidth(i)); 
		gameManager_.FloorSetup(i, floorData_.GetFloorPosition(i), floorData_.GetFloorHeight(i), floorData_.GetFloorWidth(i),floorData_.GetIsBreakable(i),floorData_.GetBreakTime(i));
	}
	for (int i = 0; i < enemyData_.GetSilentEnemyCount(); i++)
	{
		silentEnemyView_[i].Initialize(enemyData_.GetSilentEnemyPosition(i),enemyData_.GetSilentEnemyDirection(i));
		gameManager_.SilentEnemySetup(i, enemyData_.GetSilentEnemyPosition(i),enemyData_.GetSilentEnemyTimeToActive(i),enemyData_.GetSilentEnemyActiveDuration(i));
	}
	for (int i = 0; i < enemyData_.GetMoveEnemyCount(); i++)
	{
		moveEnemyView_[i].Initialize(enemyData_.GetMoveEnemyPosition(i), enemyData_.GetMoveEnemyTimeToActive(i));
		gameManager_.MoveEnemySetup(i,enemyData_.GetMoveEnemyTimeToActive(i), enemyData_.GetMoveEnemySpeed(i),enemyData_.GetMoveEnemyDirection(i), enemyData_.GetMoveEnemyPosition(i), enemyData_.GetMoveEnemyMaxRange_X(i), enemyData_.GetMoveEnemyMinRange_X(i));
	}
	for (int i = 0; i < enemyData_.GetSuitonEnemyCount(); i++)
	{
		gameManager_.SuitonEnemyPositionSetup(i, enemyData_.GetSuitonEnemyModelPosition(i).y,enemyData_.GetSuitonEnemyCollisionHeight(),enemyData_.GetSuitonEnemyCollisionWidth(),enemyData_.GetSuitonEnemyDirection(i));
		gameManager_.SuitonEnemyAttackSetup(i, enemyData_.GetSuitonEnemyApeearTime(i), enemyData_.GetSuitonEnemyAttackTime(i), enemyData_.GetSuitonEnemyAttackDuration(i), enemyData_.GetSuitonEnemyAttackAfterTime(i), enemyData_.GetAttackSuitonEnemyAmount(i));
		suitonEnemyView_[i].Initialize(enemyData_.GetSuitonEnemyViewPosition(i), enemyData_.GetSuitonEnemyDirection(i),enemyData_.GetSuitonEnemyModelPosition(i));
		suitonFusumaView_[i].Initialize(enemyData_.GetSuitonFusumaPosition(i)); // �ӂ��܂̏�����
		isPrevSuitonEnemyActive_[i] = false; // �O�̐��ق̏p�̓G���A�N�e�B�u���������ǂ���
	}
	for (int i = 0; i < enemyData_.GetKatonEnemyCount(); i++)
	{
		gameManager_.KatonEnemyPositionSetup(i, enemyData_.GetKatonEnemyModelPosition(i), enemyData_.GetKatonEnemyCollisionHeight(), enemyData_.GetKatonEnemyCollisionWidth());
		gameManager_.KatonEnemyAttackSetup(i, enemyData_.GetKatonEnemyApeearTime(i), enemyData_.GetKatonEnemyAttackTime(i), enemyData_.GetKatonEnemyAttackDuration(i), enemyData_.GetKatonEnemyAttackAfterTime(i), enemyData_.GetAttackKatonEnemyAmount(i));
		katonEnemyView_[i].Initialize(enemyData_.GetKatonEnemyViewPosition(i), enemyData_.GetKatonEnemyModelPosition(i));
		katonFusumaView_[i].Initialize(enemyData_.GetKatonFusumaPosition(i)); // �ӂ��܂̏�����
		isPrevKatonEnemyActive_[i] = false; // �O�̉Γق̏p�̓G���A�N�e�B�u���������ǂ���
	}

	markerView_.MarkerDelete(); // �}�[�J�[���폜
	playerView_.Update(gameManager_.GetPlayerModel().GetPlayerPosition(), gameManager_.GetPlayerModel().GetIsMovingToRight(), gameManager_.GetPlayerModel().GetIsGravityUpward(), gameManager_.GetPlayerInvincible().GetIsInvincible(), gameManager_.GetPlayerInvincible().GetInvincibleRemainingTime(gameManager_.GetTimer())); // �v���C���[�̈ʒu���X�V
	playerView_.AnimStop(); // �v���C���[�̃A�j���[�V�������~
	invincibleItemView_.Update(gameManager_.GetInvincibleItemModel().GetItemPosition(), gameManager_.GetInvincibleItemModel().GetIsActive()); // ���G�A�C�e���̈ʒu���X�V
	EnemyViewUpdate(); // �G�̃r���[���X�V

	countdownView_.ShowCountDown();

	isPrevGravityUpward_ = gameManager_.GetPlayerModel().GetIsGravityUpward(); // �O�̏d�͕�������������������ǂ�����������
	isPrevPlayerInvincible_ = gameManager_.GetPlayerInvincible().GetIsInvincible(); // �O�̃v���C���[�����G���������ǂ�����������
	isSceceMovingToMain_ = false; // �V�[�����ړ������ǂ�����������
	isSceceMovingToTitle_ = false; // �V�[�����^�C�g���Ɉړ������ǂ�����������
	prevSelectedMenu_ = selectedMenu_ = 0; // �O��I�����ꂽ���j���[��������
}

// releasing resources required for termination.
void MainScene::Terminate()
{

}

// updates the scene.
void MainScene::Update(float deltaTime)
{
	switch (gameState_)
	{
	case 0: // �Q�[����
		MoniteringGameManager();
		if (InputSystem.Keyboard.wasPressedThisFrame.Space) {
			gameManager_.GravityChange(); // �X�y�[�X�L�[�������ꂽ��d�͂̌�����ύX
		}
		gameManager_.Update();
		playerView_.Update(gameManager_.GetPlayerModel().GetPlayerPosition(),gameManager_.GetPlayerModel().GetIsMovingToRight(),gameManager_.GetPlayerModel().GetIsGravityUpward(),gameManager_.GetPlayerInvincible().GetIsInvincible(),gameManager_.GetPlayerInvincible().GetInvincibleRemainingTime(gameManager_.GetTimer())); // �v���C���[�̈ʒu���X�V
		invincibleItemView_.Update(gameManager_.GetInvincibleItemModel().GetItemPosition(),gameManager_.GetInvincibleItemModel().GetIsActive()); // ���G�A�C�e���̈ʒu���X�V
		EnemyViewUpdate(); // �G�̃r���[���X�V
		NotificateTime(); // �^�C�}�[�̒ʒm��\��

		if (countdownView_.GetCurrentFrame() >= 10) {
			countdownView_.HideCountDown(); // �J�E���g�_�E�����\���ɂ���
		}
		

		break;
	case 1: // �Q�[���I�[�o�[
		gameOverView_.ShowGameOver(1,gameManager_.GetTimerModel().GetTimer()); // �Q�[���I�[�o�[��ʂ�\��
		timerView_.HideNotification(); // �^�C�}�[�̒ʒm���\��
		playerView_.AnimStop(); // �v���C���[�̃A�j���[�V�������~
		for (int i = 0; i < enemyData_.GetMoveEnemyCount(); i++)
		{
			moveEnemyView_[i].AnimStop(); // �藠���̃A�j���[�V�������~
		}
		SelectMenu(); // ���j���[��I������
		MarkerUpdate(); // �}�[�J�[���X�V
		if (isSceceMovingToMain_ && !seManager_.GetIsSEPlaying(2)) {
			SceneManager.SetNextScene(NextScene::MainScene);
		}
		if (isSceceMovingToTitle_ && !seManager_.GetIsSEPlaying(1))
		{
			SceneManager.SetNextScene(NextScene::TitleScene); // �^�C�g���V�[���Ɉړ�
		}
		break;
	case 2: // �Q�[���N���A
		gameOverView_.ShowGameOver(2, gameManager_.GetTimerModel().GetTimer()); // �Q�[���N���A��ʂ�\��
		timerView_.HideNotification(); // �^�C�}�[�̒ʒm���\��s
		playerView_.AnimStop(); // �v���C���[�̃A�j���[�V�������~
		for (int i = 0; i < enemyData_.GetMoveEnemyCount(); i++)
		{
			moveEnemyView_[i].AnimStop(); // �藠���̃A�j���[�V�������~
		}
		SelectMenu(); // ���j���[��I������
		MarkerUpdate(); // �}�[�J�[���X�V
		if (isSceceMovingToMain_ && !seManager_.GetIsSEPlaying(2)) {
			SceneManager.SetNextScene(NextScene::MainScene);
		}
		if (isSceceMovingToTitle_ && !seManager_.GetIsSEPlaying(1))
		{
			SceneManager.SetNextScene(NextScene::TitleScene); // �^�C�g���V�[���Ɉړ�
		}
		break;
	case 3://�Q�[���J�n�O
		if (countdownView_.GetCurrentFrame() >= 30) {
			countdownView_.ShowStart(); // �J�n
			playerView_.AnimStart(); // �v���C���[�̃A�j���[�V�������J�n
			gameState_ = 0; // �Q�[���J�n
		}
		if (countdownView_.GetCurrentFrame() % 10 == 1) {
			seManager_.PlaySE(3); // �J�E���g�_�E����SE���Đ�
		}

		break;
	}
	SoundControl(); // SE�̐���
	Scene::Update(deltaTime);
}


void MainScene::EnemyViewUpdate() {
	for (int i = 0; i < enemyData_.GetSilentEnemyCount(); i++) {
		silentEnemyView_[i].Update(gameManager_.GetSilentEnemy(i).GetIsActive());
	}
	for (int i = 0; i < enemyData_.GetMoveEnemyCount(); i++)
	{
		moveEnemyView_[i].Update(gameManager_.GetMoveEnemy(i).GetEnemyPosition(), gameManager_.GetTimerModel().GetTimer());
	}
	for (int i = 0; i < enemyData_.GetSuitonEnemyCount(); i++)
	{
		suitonEnemyView_[i].Update(gameManager_.GetSuitonEnemy(i).GetIsActive(), gameManager_.GetSuitonEnemy(i).GetSuitonEnemyState(),gameManager_.GetSuitonEnemy(i).GetSuitonEnemyPosition());
		if (isPrevSuitonEnemyActive_[i] != gameManager_.GetSuitonEnemy(i).GetIsActive()) {
			suitonFusumaView_[i].FusumaMove(gameManager_.GetSuitonEnemy(i).GetIsActive()); // �ӂ��܂̕\�����X�V
			seManager_.PlaySE(7); // �ӂ��܂�SE���Đ�
			isPrevSuitonEnemyActive_[i] = gameManager_.GetSuitonEnemy(i).GetIsActive(); // �O�̐��ق̏p�̓G���A�N�e�B�u���������ǂ������X�V
		}
	
	}
	for (int i = 0; i < enemyData_.GetKatonEnemyCount(); i++)
	{
		katonEnemyView_[i].Update(gameManager_.GetKatonEnemy(i).GetIsActive(), gameManager_.GetKatonEnemy(i).GetSuitonEnemyState());
		if (isPrevKatonEnemyActive_[i] != gameManager_.GetKatonEnemy(i).GetIsActive()) {
			katonFusumaView_[i].FusumaMove(gameManager_.GetKatonEnemy(i).GetIsActive()); // �ӂ��܂̕\�����X�V
			seManager_.PlaySE(7); // �ӂ��܂�SE���Đ�
			isPrevKatonEnemyActive_[i] = gameManager_.GetKatonEnemy(i).GetIsActive(); // �O�̉Γق̏p�̓G���A�N�e�B�u���������ǂ������X�V
		}
	}
}

void MainScene::NotificateTime()
{
	bool notified = false;
	for (int i = 0; i < notificationCount_; i++)
	{
		if (gameManager_.GetTimer() >= notificationTime_[i] && gameManager_.GetTimer() < notificationTime_[i] + notificatingTime)
		{
			timerView_.NotifiCateTime(timeLimit_ - notificationTime_[i]);
			notified = true;
			break; // 1�ł��Y������Βʒm
		}
	}
	if (!notified)
	{
		timerView_.HideNotification();
	}
}


void MainScene::MoniteringGameManager()
{
	gameState_ = gameManager_.GetGameState(); // �Q�[���I�[�o�[��Ԃ��擾
	for (int i = 0; i < gameManager_.GetFloorCount(); i++) {
		if (gameManager_.GetFloorModel(i).GetIsBroken()) {
			floorView_[i].FloorBreak(); // ������ꂽ�珰�̃r���[���X�V
		}
	}
}

void MainScene::SelectMenu()
{
	if (isSceceMovingToMain_ || isSceceMovingToTitle_)return; // �V�[�����ړ����̏ꍇ�̓��j���[�I���𖳌���
	if (InputSystem.Keyboard.wasPressedThisFrame.Up) {
		selectedMenu_--; // ��L�[�Ń��j���[����Ɉړ�
	}
	if (InputSystem.Keyboard.wasPressedThisFrame.Down) {
		selectedMenu_++; // ���L�[�Ń��j���[�����Ɉړ�
	}
	if (selectedMenu_ <= 0)
	{
		selectedMenu_ = 0; // �����0�ɐ���
	}
	if (selectedMenu_ >= menuCount_)
	{
		selectedMenu_ = menuCount_ - 1; // ���������j���[��-1�ɐ���
	}
	if (InputSystem.Keyboard.wasPressedThisFrame.Enter) {
		if (selectedMenu_ == 0) {

			seManager_.PlaySE(2); // SE���Đ�
			isSceceMovingToMain_ = true; // �V�[�����ړ����ł��邱�Ƃ�����
		}
		else if (selectedMenu_ == 1) {
			seManager_.PlaySE(1); // SE���Đ�
			isSceceMovingToTitle_ = true; // �V�[�����ړ����ł��邱�Ƃ�����
		}
	}
}

void MainScene::MarkerUpdate()
{
	switch (selectedMenu_)
	{
	case 0:
		markerView_.UpdateMarker(Math::Vector2(340.0f, 490.0f)); // Start menu position
		break;
	case 1:
		markerView_.UpdateMarker(Math::Vector2(340.0f, 605.0f)); // Tutorial menu position
		break;
	}
}

void MainScene::SoundControl()
{
	if (isPrevGravityUpward_ != gameManager_.GetPlayerModel().GetIsGravityUpward()) {
		seManager_.PlaySE(9);
		isPrevGravityUpward_ = gameManager_.GetPlayerModel().GetIsGravityUpward(); // �O�̏d�͕������X�V
	}
	if (isPrevPlayerInvincible_ != gameManager_.GetPlayerInvincible().GetIsInvincible()) {
		if (gameManager_.GetPlayerInvincible().GetIsInvincible()) {
			bgmManager_.PlayBGMFromTop(2); // �v���C���[�����G��ԂɂȂ����疳�GBGM���Đ�
		}
		else {
			bgmManager_.PlayBGMContinue(0); // �v���C���[�����G��ԂłȂ��Ȃ�����ʏ�BGM���Đ�
		}
		isPrevPlayerInvincible_ = gameManager_.GetPlayerInvincible().GetIsInvincible(); // �O�̃v���C���[�̖��G��Ԃ��X�V
	}
	for (int i = 0; i < enemyData_.GetSuitonEnemyCount(); i++)
	{
		if (prevSuitonEnemyState_[i] != gameManager_.GetSuitonEnemy(i).GetSuitonEnemyState()) {
			if (gameManager_.GetSuitonEnemy(i).GetSuitonEnemyState() == 1) {
				seManager_.PlaySE(6); // ���ق̏p�̓G���A�N�e�B�u�ɂȂ�����SE���Đ�
			}
			prevSuitonEnemyState_[i] = gameManager_.GetSuitonEnemy(i).GetSuitonEnemyState(); // �O�̐��ق̏p�̓G�̏�Ԃ��X�V
		}
	}
	for (int i = 0; i < enemyData_.GetKatonEnemyCount(); i++)
	{
		if (prevKatonEnemyState_[i] != gameManager_.GetKatonEnemy(i).GetSuitonEnemyState()) {
			if (gameManager_.GetKatonEnemy(i).GetSuitonEnemyState() == 1) {
				seManager_.PlaySE(5); // �Γق̏p�̓G���A�N�e�B�u�ɂȂ�����SE���Đ�
			}
			prevKatonEnemyState_[i] = gameManager_.GetKatonEnemy(i).GetSuitonEnemyState(); // �O�̉Γق̏p�̓G�̏�Ԃ��X�V
		}
	}
	if (gameManager_.GetTimer() == 10.0f || gameManager_.GetTimer() == 30.0f) {
		seManager_.PlaySE(11);
	}
	if (prevSelectedMenu_ != selectedMenu_) {
		seManager_.PlaySE(1); // ���j���[�I����SE���Đ�
		prevSelectedMenu_ = selectedMenu_; // �O��I�����ꂽ���j���[���X�V
	}
	if (prevGameState_ != gameState_) {
		switch (gameState_)
		{
		case 0: // �Q�[����
			bgmManager_.PlayBGMFromTop(0); // BGM���Đ�
			seManager_.PlaySE(4); // �Q�[������SE���Đ�
			prevGameState_ = gameState_; // �O�̃Q�[����Ԃ��X�V
			break;
		case 1: // �Q�[���I�[�o�[
			bgmManager_.StopBGM(); // BGM���~
			seManager_.PlaySE(8); // �Q�[���I�[�o�[��SE���Đ�
			prevGameState_ = gameState_; // �O�̃Q�[����Ԃ��X�V
			break;
		case 2: // �Q�[���N���A
			bgmManager_.StopBGM(); // BGM���~
			seManager_.PlaySE(10); // �Q�[���N���A��SE���Đ�
			prevGameState_ = gameState_; // �O�̃Q�[����Ԃ��X�V
			break;
		}
	   
	}


}

