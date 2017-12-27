using TestClass

public namespace Test.TestClass
{
    [TestFixture]
    public class TestTestClass
    {
        private IClassOne _classOne;
        private IClassTwo _classTwo;
        private IClassThree _classThree;
        
        [SetUp]
        public void Setup()
        {
            _classOne = NSubstitute.Substitute();
        }
    }
}
