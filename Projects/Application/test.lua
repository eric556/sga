-- Get instance of EntityManager
em = EntityManager.new()

-- Create entity
player = em:createEntity()
player.name = "Player"
player:addDisplay()
player:addTransform()
player:addKineticBody()
player:addInput()
player:addTag(5)
