class Solution {
    unordered_set<string> Supplies;
    unordered_map<string, vector<string>> RecipeToIngredients;
    unordered_map<string, int> Visited;
    vector<string> PossibleRecipes;
    int N = 0;
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies)
    {
        for(string& Supply : supplies)
        {
            Supplies.insert(Supply);
        }
        
        N = static_cast<int>(recipes.size());
        for(int i = 0; i < N; i++)
        {
            RecipeToIngredients[recipes[i]] = ingredients[i];
        }

        for(int i = 0; i < N; i++)
        {
            bPossibleCook(recipes[i], ingredients, recipes);
        }
        
        return PossibleRecipes;
    }
private:
    bool bPossibleCook(const string& Recipe, vector<vector<string>>& Ingredients, vector<string>& Recipes)
    {   
        if(Visited.count(Recipe))
        {
            return Visited[Recipe] == 1;
        }
        if(Supplies.count(Recipe))
        {
            return true;
        }
        if(!RecipeToIngredients.count(Recipe))
        {
            return false;
        }

        Visited[Recipe] = 0;

        for(const string& Ingredient : RecipeToIngredients[Recipe])
        {
            if(!bPossibleCook(Ingredient, Ingredients, Recipes))
            {
                Visited[Recipe] = -1;
                return false;
            }
        }

        Visited[Recipe] = 1;
        PossibleRecipes.push_back(Recipe);
        return true;
    }
};