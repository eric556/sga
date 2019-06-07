entity = entityManager:createEntity()
entity.name = "Player"
display = entity:addDisplay()
display.shape:setSize(Vector2.new(100, 100))
display.shape:setColor(Color.new(100, 0, 0, 255))
display.shape:setOrigin(50, 50)
transform = entity:addTransform()
transform.position = Vector3.new(1920 / 2, 1080 / 2, 0)
input = entity:addInput()
input.speed = 500
kb = entity:addKineticBody()