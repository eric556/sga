size = EntityManager.entities:size()
print(size)
for i=1,size do
    entityManager:deleteEntity(EntityManager.entities[i].id)
end