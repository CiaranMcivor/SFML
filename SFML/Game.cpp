#include "Game.h"

Game::Game() : m_window("Shrooms", sf::Vector2u(1920,1080))
{
	m_mushroomTexture.loadFromFile("Assets/Textures/Mushroom.png");
	m_mushroomSprite.setTexture(m_mushroomTexture);
	m_increment = sf::Vector2i(400,400);
}

Game::~Game()
{
}

void Game::HandleInput()
{
}

void Game::Update()
{
	m_window.Update();
	MoveMushroom();
}

void Game::Render()
{
	m_window.BeginDraw();
	m_window.Draw(m_mushroomSprite);
	m_window.EndDraw();
}

Window * Game::GetWindow()
{
	return &m_window;
}

sf::Time Game::GetElapsed()
{
	return m_elapsed;
}

void Game::RestartClock()
{
	m_elapsed = m_clock.restart();
}


void Game::MoveMushroom()
{
	sf::Vector2u l_windSize = m_window.GetWindowSize();
	sf::Vector2u l_textureSize = m_mushroomTexture.getSize();

	if ((m_mushroomSprite.getPosition().x > l_windSize.x - l_textureSize.x && m_increment.x > 0) || (m_mushroomSprite.getPosition().x < 0 && m_increment.x < 0)) 
	{
		m_increment.x = -m_increment.x;
		m_mushroomSprite.setColor(sf::Color::Green);
	}

	if ((m_mushroomSprite.getPosition().y > l_windSize.y - l_textureSize.y && m_increment.y > 0) || (m_mushroomSprite.getPosition().y < 0 && m_increment.y < 0))
	{
		m_increment.y = -m_increment.y;

		m_mushroomSprite.setColor(sf::Color::Blue);
	}

	float fElapsed = m_elapsed.asSeconds();
	m_mushroomSprite.setPosition(m_mushroomSprite.getPosition().x + (m_increment.x * fElapsed), m_mushroomSprite.getPosition().y + (m_increment.y * fElapsed));
}
